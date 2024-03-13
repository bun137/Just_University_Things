}

int postorderAlternateSum(Node *root)
{
    int sum = 0;
    postorderAlternateSumUtil(root, &sum, 1);
    return sum;
}

void countConsecutivePairsUtil(Node *root, int prev, int *count)
{
    if (root == NULL)
    {
        return;
    }
    countConsecutivePairsUtil(root->left, prev, count);
    if (prev != -1 && root->data == prev + 1)
    {
        (*count)++;
    }
    countConsecutivePairsUtil(root->right, root->data, count);
}

int countConsecutivePairs(Node *root, int prev, int *count)
{
    countConsecutivePairsUtil(root, prev, count);
    return *count;
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
   