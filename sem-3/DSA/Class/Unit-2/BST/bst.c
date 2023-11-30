
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    struct tnode *lchild;
    int data;
    struct tnode *rchild;
} TNODEE;

TNODEE *insert(TNODEE *root, int ele)
{
    TNODEE *newnode;
    TNODEE *parent_prev = NULL; // Initialize to NULL
    TNODEE *child = root;       // Initialize to root

    newnode = malloc(sizeof(TNODEE));
    newnode->data = ele;
    newnode->lchild = NULL;
    newnode->rchild = NULL;

    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    else
    { // tree != empty
        while (child != NULL)
        {
            parent_prev = child;
            if (ele > (child->data))
            {
                child = child->rchild;
            }
            else
            {
                child = child->lchild;
            }
        }

        if (ele > parent_prev->data)
        {
            parent_prev->rchild = newnode;
        }
        else
        {
            parent_prev->lchild = newnode;
        }
    }
    return root;
}

int count(TNODEE *root)
{
    int lc = 0;
    int rc = 0;
    if (root != NULL)
    {
        lc = count(root->lchild);
        rc = count(root->rchild);
        return (lc + rc + 1);
    }
    return 0;
}

void inorder(TNODEE *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void preorder(TNODEE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(TNODEE *root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

int findmin(TNODEE *root)
{
    int minvalue;
    TNODEE *current;
    current = root;
    while (current->lchild != NULL)
    {
        current = current->lchild;
    }
    minvalue = current->data;
    return minvalue;
}

TNODEE *insucc(TNODEE *root)
{
    TNODEE *current;
    current = root;
    current = current->rchild;
    while (current->lchild != NULL)
    {
        current = current->lchild;
    }
    return (current);
}

int height(TNODEE *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int htlc = height(root->lchild);
    int htrc = height(root->rchild);
    if (htlc > htrc){
        return (htlc + 1);
    }else{
        return (htrc+1);
    }

}

// int leafnodes(TNODEE *root)
// {
//     int lc = 0;
//     int rc = 0;
//     if (root != NULL)
//     {
//         lc = count(root->lchild);
//         rc = count(root->rchild);
//         return (lc + rc);
//     }
//     return 0;
// }

int search(TNODEE *root, int data)
{
    TNODEE *droot;
    droot = root;

    while (droot != NULL)
    {
        if (droot->data == data)
        {
            return 1;
        }
        else if (data < droot->data)
        {
            droot = droot->lchild;
        }
        else
        {
            droot = droot->rchild;
        }
    }
    return 0;
}

void print_bst(TNODEE* root, int space){
    if ( root == NULL){
        return;
    }
    else{
        space += 5;
        print_bst(root -> rchild, space);
        for(int i = 5; i < space ; i++){
            printf(" ");
        }
        printf("%d\n", root-> data);
        print_bst(root-> lchild, space);
    }
}

int main()
{
    TNODEE *root = NULL;
    int ele;
    for (int i = 0; i < 10; i++)
    {
        printf("heyy, whats the ele: ");
        scanf("%d", &ele);
        root = insert(root, ele);
    }
    inorder(root);
    printf("\n\n");
    preorder(root);
    printf("\n\n");
    postorder(root);
    printf("\n\n");
    printf("%d", count(root));
    printf("\n");
    printf("the number of leaf nodes are: %d", leafnodes(root));
    printf("\n");
    printf("%d \n", height(root));
    printf("%d \n", findmin);
    print_bst(root, 0);
    return 0;
}