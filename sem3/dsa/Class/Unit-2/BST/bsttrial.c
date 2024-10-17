#include<stdio.h>
#include<stdlib.h>

typedef struct tnode{
    struct tnode *lchild;
    int data;
    struct tnode *rchild;
}TNODEE;

TNODEE * insert(TNODEE *root, int ele){
    TNODEE* newnode;
    TNODEE *parent_prev = NULL;  // Initialize to NULL
    TNODEE *child = root;       // Initialize to root

    newnode = malloc(sizeof(TNODEE));
    newnode -> data = ele;
    newnode -> lchild = NULL;
    newnode -> rchild = NULL;

    if(root == NULL){
        root = newnode ;
        return root;
    } else { // tree != empty
        while(child != NULL){
            parent_prev = child;
            if (ele > (child -> data)){
                child = child -> rchild;
            } else {
                child = child -> lchild;
            }
        }

        if (ele > parent_prev -> data){
            parent_prev -> rchild = newnode;
        } else {
            parent_prev -> lchild = newnode;
        }
    }
    return root;
}


void inorder(TNODEE *root){
    if (root != NULL){
        inorder(root -> lchild);
        printf("%d ", root -> data);
        inorder (root -> rchild);
    }
}

void preorder(TNODEE *root){
    if (root != NULL){
        printf("%d ", root -> data);
        preorder(root -> lchild);
        preorder (root -> rchild);
    }
}

void postorder(TNODEE *root){
    if (root != NULL){
    postorder(root -> lchild);
    postorder (root -> rchild);   
    printf("%d ", root -> data);
    }
}

int findmin(TNODEE* root){
    int minvalue;
    TNODEE*current;
    current = root;
    while(current -> lchild != NULL){
        current = current -> lchild;
    }
    minvalue = current -> data;
    return minvalue;
}

TNODEE *insucc(TNODEE*root){
    TNODEE* current;
    current = root;
    current = current -> rchild;
    while(current -> lchild != NULL){
        current = current -> lchild;
    }return (current);
}

int main(){
    TNODEE* root = NULL;
    int ele;
    for(int i =0; i< 8; i++){
    printf("heyy, whats the ele: ");
    scanf("%d",&ele);
    root = insert(root, ele);}
    return 0;

}