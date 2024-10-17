#include <stdio.h>
#define MAX 50

typedef struct Dequeue
{
    int data[MAX];
    int rear, front;
} Dequeue;

void initializeDeque(Dequeue *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Dequeue *dq)
{
    return dq->front == -1;
}

int isFull(Dequeue *dq)
{
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == (dq->rear + 1) % MAX);
}

void insert(Dequeue *dq, int entry, int item)
{
    // Write your code here
    if (isFull(dq))
    {
        return;
    }
    if (entry == 1)
    {
        if (dq->front == -1)
        {
            dq->front = 0;
            dq->rear = 0;
        }
        else if (dq->front == 0)
            dq->front = MAX - 1;
        else
            dq->front = (dq->front - 1 + MAX) % MAX;
        dq->data[dq->front] = item;
    }
    else if (entry == 2)
    {
        if (dq->front == -1)
        {
            dq->front = 0;
            dq->rear = 0;
        }
        else
            dq->rear = (dq->rear + 1) % MAX;
        dq->data[dq->rear] = item;
    }
}

void delete(Dequeue *dq, int entry)
{
    // Write your code here
    if (isEmpty(dq))
    {
        return;
    }
    if (entry == 1)
    {
        if (dq->front == dq->rear)
        {
            dq->front = -1;
            dq->rear = -1;
        }
        else
            dq->front = (dq->front + 1) % MAX;
    }
    else if (entry == 2)
    {
        if (dq->front == dq->rear)
        {
            dq->front = -1;
            dq->rear = -1;
        }
        else
            dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
}

void rotate(Dequeue *dq, int rotations)
{
    // Write your code here
    if (isEmpty(dq))
    {
        return;
    }

    while (rotations > 0)
    {
        int temp = dq->data[dq->front];
        for (int i = dq->front; i != dq->rear; i = (i + 1) % MAX)
        {
            dq->data[i] = dq->data[(i + 1) % MAX];
        }
        dq->data[dq->rear] = temp;
        rotations--;
    }
}

int findGreater(Dequeue *dq, int entry, int num)
{
    // Write your code here
    if (isEmpty(dq))
    {
        return -1;
    }
    if (entry == 1)
    {
        int a = dq->front;
        while (1)
        {
            if (dq->data[a] > num)
                return dq->data[i];
            if (a == dq->rear)
                break;
            a = (a + 1) % MAX;
        }
    }
    else if (entry == 2)
    {
        int i = dq->rear;
        while (1)
        {
            if (dq->data[i] > num)
                return dq->data[i];
            if (i == dq->front)
                break;
            i = (i - 1 + MAX) % MAX;
        }
    }
    return -1;
}
// Driver code
int main()
{
    Dequeue deque;
    initializeDeque(&deque);
    int n, operation, entry, item, result;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            scanf("%d %d", &entry, &item);
            insert(&deque, entry, item);
            break;
        case 2:
            scanf("%d", &entry);
            delete(&deque, entry);
            break;
        case 3:
            scanf("%d", &item);
            rotate(&deque, item);
            break;
        case 4:
            scanf("%d %d", &entry, &item);
            result = findGreater(&deque, entry, item);
            printf("%d\n", result);
            break;
        }
    }
    return 0;
}