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
    Node *nodeNew = (Node *)malloc(sizeof(Node));
    nodeNew->data = value;
    nodeNew->left = NULL;
    nodeNew->right = NULL;
   return newNode;
}

Node *insert(Node *root, int value){
    if (root == NULL)    {
        return createNode(value);
    }
    if (value < root->data)    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)    {
        root->right = insert(root->right, value);
    }
    return root;
}

Node *mini_value(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int value){
    if (root == NULL)    {
        return root;
    }
    if (value < root->data)    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)    {
        root->right = deleteNode(root->right, value);
    }
    else    {
        if (root->left == NULL)        {
            Node *t = root->right;
            free(root);
            return t;
        }
        else if (root->right == NULL)        {
            Node *t = root->left;
            free(root);
            return t;
        }
        Node *t = mini_value(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int postorderAlternateSum(Node *root, int *stage)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = postorderAlternateSum(root->left, stage);
    int rs = postorderAlternateSum(root->right, stage);

    int sum = 0;
    if (*stage % 2 == 0)
    {
        sum = root->data;
    }

    *stage += 1;

    return sum + ls + rs;
}

int countConsecutivePairs(Node *root, int prev, int *count)
{
    if (root == NULL)
    {
        return prev;
    }
    prev = countConsecutivePairs(root->left, prev, count);
    if (prev != -1 && root->data - prev == 1)
    {
        (*count)++;
    }
    prev = root->data;
    prev = countConsecutivePairs(root->right, prev, count);
    return prev;
}
// Driver code
int main()
{
    Node *root = NULL;
    int stage = 0;
    int operation, value, alternateSum, sum, consecutivePairsCount = 0, N;
    scanf("%d", &N);
    if(N==0){
        return 0;
    }
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
            alternateSum = postorderAlternateSum(root,&stage);
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
