#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value)
{
    // Write your code here
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data){

        
            root->left = insert(root->left, value);
        
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
Node *deleteNode(Node *root, int value){
    if(root==NULL){
        return root;
    }
    if(value < root->data){
        
    }
}

    int postorderAlternateSum(Node *root)
{
    // Write your code here
}

int countConsecutivePairs(Node *root, int prev, int *count)
{
    // Write your code here
}

// Driver code
int main()
{
    Node *root = NULL;
    int operation, value, alternateSum, sum, consecutivePairsCount = 0, N;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:
            alternateSum = postorderAlternateSum(root);
            printf("%d\n", alternateSum);
            break;
        case 4:
            countConsecutivePairs(root, -1, &consecutivePairsCount);
            printf("%d\n", consecutivePairsCount);
            consecutivePairsCount = 0;
            break;
        }
    }
    return 0;
}