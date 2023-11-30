int main()
{
    int N;
    char data;
    scanf("%d", &N);
    getchar();

    if (N <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    struct Node *head = NULL;
    for (int i = 0; i < N; i++)
    {
        fflush(stdin);
        scanf(" %c", &data);
        insertAtEnd(&head, data);
    }

    removeVowels(&head);
    printReverse(head);
    return 0;
}
