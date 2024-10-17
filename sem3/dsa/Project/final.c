#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

typedef enum {head, entry} tagfield;

typedef struct {
    int row;
    int col;
    int value;
} entryNode;

struct MN {
    struct MN *down;
    struct MN *right;
    tagfield tag;
    union {
        struct MN *next;
        entryNode entry;
    } u;
};

typedef struct MN *matrixPointer;
matrixPointer hdnode[MAX_SIZE];

matrixPointer Read_Sparse()
{
    int numRows, numCols,numTerms,numHeads,i;
    int row, col,value,currentRow;
    matrixPointer temp,last,node;
    printf("Enter number of rows, columns, and number of non zero terms: ");
    scanf("%d %d %d",&numRows,&numCols,&numTerms);
    numHeads=(numCols > numRows)? numCols : numRows;

    node = (matrixPointer) malloc(sizeof(struct MN));
    node->tag = entry;
    node->u.entry.row = numRows;
    node->u.entry.col = numCols;
    if (!numHeads) node ->right = node;
    else{
        for(i=0;i<numHeads;i++)
        {
            temp = (matrixPointer)malloc(sizeof(struct MN));
            hdnode[i]= temp;
            hdnode[i]->tag = head;
            hdnode[i]->right = temp;
            hdnode[i]->u.next = temp;
        }

        currentRow=0;
        last = hdnode[0];
        for(i=0;i<numTerms;i++)
        {
            printf("Enter rows, column and value: ");
            scanf("%d%d%d",&row,&col,&value);
            if(row>currentRow)
            {
                last->right= hdnode[currentRow];
                currentRow = row;
                last = hdnode[row];
            }
            temp = (matrixPointer) malloc(sizeof(*temp));
            temp->tag= entry;
            temp->u.entry.row = row;
            temp->u.entry.col = col;
            temp->u.entry.value = value;
            last->right = temp;
            last = temp;

            hdnode[col]->u.next->down =temp;
            hdnode[col]->u.next = temp;

        }

        last->right = hdnode[currentRow];

        for(i=0;i<numCols;i++)
        {
            hdnode[i]->u.next->down = hdnode[i];
        }

        for(i=0;i<numHeads-1;i++)
        {
            hdnode[i]->u.next = hdnode[i+1];
        }

        hdnode[numHeads-1]->u.next = node;
        node->right = hdnode[0];
    }

    return node;
}



void Print_Sparse(matrixPointer node){
    int i;
    matrixPointer temp,head;
    head=node->right;
    printf("numsRows= %d, numsCols= %d\n", node->u.entry.row, node->u.entry.col);
    printf("The matrix by row, col and value: \n");
    for(int i=0;i<node->u.entry.row;i++){
        for(temp=head->right;temp!=head;temp=temp->right){
            printf("%5d %5d %5d", temp->u.entry.row,temp->u.entry.col,temp->u.entry.value);
            printf("\n");
        }
        head=head->u.next;
    }
}


void Delete_Matrix(matrixPointer node) {
    matrixPointer temp, current, next;

    for (int i = 0; i < node->u.entry.row; i++) {
        current = node->right->right;
        while (current != node->right) {
            next = current->right;
            free(current);
            current = next;
        }
        temp = node->right;
        node->right = node->right->u.next;
        free(temp);
    }

    free(node);
    printf("Matrix deleted successfully.\n");
}


matrixPointer Transpose_Matrix(matrixPointer node) {
    matrixPointer transposedNode, temp, current, newNode, last;
    matrixPointer transposedColumnHeads[MAX_SIZE];

    transposedNode = (matrixPointer)malloc(sizeof(struct MN));
    transposedNode->tag = entry;
    transposedNode->u.entry.row = node->u.entry.col;
    transposedNode->u.entry.col = node->u.entry.row;

    if (!transposedNode->u.entry.row)
        transposedNode->right = transposedNode;
    else {
        for (int i = 0; i < transposedNode->u.entry.row; i++) {
            temp = (matrixPointer)malloc(sizeof(struct MN));
            transposedColumnHeads[i] = temp;
            transposedColumnHeads[i]->tag = head;
            transposedColumnHeads[i]->right = transposedColumnHeads[i];
            transposedColumnHeads[i]->u.next = transposedColumnHeads[i];
        }

        current = node->right;
        while (current != node) {
            temp = current->down;
            while (temp != current) {
                newNode = (matrixPointer)malloc(sizeof(struct MN));
                newNode->tag = entry;
                newNode->u.entry.row = temp->u.entry.col;
                newNode->u.entry.col = temp->u.entry.row;
                newNode->u.entry.value = temp->u.entry.value;

                last = transposedColumnHeads[newNode->u.entry.row];
                while (last->right != transposedColumnHeads[newNode->u.entry.row])
                    last = last->right;

                last->right = newNode;
                newNode->right = transposedColumnHeads[newNode->u.entry.row];

                transposedColumnHeads[newNode->u.entry.row]->u.next->down = newNode;
                transposedColumnHeads[newNode->u.entry.row]->u.next = newNode;

                temp = temp->down;
            }
            current = current->u.next;
        }

        for (int i = 0; i < transposedNode->u.entry.row; i++) {
            transposedColumnHeads[i]->u.next->down = transposedColumnHeads[i];
        }

        for (int i = 0; i < transposedNode->u.entry.row - 1; i++) {
            transposedColumnHeads[i]->u.next = transposedColumnHeads[i + 1];
        }

        transposedColumnHeads[transposedNode->u.entry.row - 1]->u.next = transposedNode;
        transposedNode->right = transposedColumnHeads[0];
    }

    return transposedNode;
}


int IsLowerTriangular_Matrix(matrixPointer node) {
    if (node->tag != entry) {
        printf("Not a valid matrix.\n");
        return 0;
    }

    matrixPointer temp = node->right;
    int currentRow = 0;

    while (temp != node) {
        matrixPointer current = temp->right;

        while (current != temp) {
            if (current->u.entry.row < currentRow) {
                return 0;
            }

            current = current->right;
        }

        temp = temp->u.next;
        currentRow++;
    }

    return 1;
}



int main() {
    matrixPointer p = NULL;
    matrixPointer transposedMatrix = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create Matrix\n2. Display Matrix\n3. Transpose Matrix\n4. Check Lower Triangular\n5. Delete Matrix\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (p != NULL) {
                    printf("Matrix already exists. Delete it first.\n");
                } else {
                    p = Read_Sparse();
                    printf("Matrix created successfully.\n");
                }
                break;

            case 2:
                if (p != NULL) {
                    printf("Original Matrix:\n");
                    Print_Sparse(p);
                } else {
                    printf("Matrix does not exist. Create it first.\n");
                }
                break;

            case 3:
                if (p != NULL) {
                    transposedMatrix = Transpose_Matrix(p);
                    printf("Transpose Matrix:\n");
                    Print_Sparse(transposedMatrix);
                } else {
                    printf("Matrix does not exist. Create it first.\n");
                }
                break;

            case 4:
                if (p != NULL) {
                    int result = IsLowerTriangular_Matrix(p);
                    if (result) {
                        printf("The matrix is lower triangular.\n");
                    } else {
                        printf("The matrix is not lower triangular.\n");
                    }
                } else {
                    printf("Matrix does not exist. Create it first.\n");
                }
                break;
            

            case 5:
                if (p != NULL) {
                    Delete_Matrix(p);
                    p = NULL;  
                } else {
                    printf("Matrix does not exist.\n");
                }
                break;

            case 6:
                if (p != NULL) {
                    Delete_Matrix(p);
                    p = NULL;  
                }
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}