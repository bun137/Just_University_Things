#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int front;
    int rear;
    int capacity;
    int* array;
} QUEUEE;

void createQueue(int size)
{
    QUEUEE* queue = (QUEUEE*)malloc(sizeof(QUEUEE));
    queue->capacity = size;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
}

int isfull(QUEUEE* Q)
{
    if (Q->front == (Q->rear + 1) % Q->capacity) {
        return 1;
    }
    else {
        return 0;
    }
}

int insertQ(QUEUEE* Q, int ele)
{
    if (!isfull(Q)) {
        Q->rear = (++Q->rear) % Q->capacity;
        Q->array[Q->rear] = ele;
        if (Q->front == -1) {
            Q->front = 0;
        }
        return 1;
    }
    return -1;
}

int isempty(QUEUEE* Q)
{
    if (Q->front == -1) {
        return 1;
    }
    return 0;
}

int deleQ(QUEUEE* Q)
{
    int ele;
    if (isempty(Q)) {
        printf("queue is empty, deletion failed");
        return -1;
    }
    else {
        ele = Q->array[Q->front];
        if (Q->front == Q->rear) {
            Q->front = -1;
            Q->rear = -1;
        }
        else {
            Q->front = (++Q->front) % Q->capacity;
        }
        return 1;
    }
}

void display(QUEUEE Q)
{
    if (isempty(&Q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = Q.front;
    printf("Queue elements: ");
    while (i != Q.rear) {
        printf("%d ", Q.array[i]);
        i = (i + 1) % Q.capacity;
    }
    printf("%d\n", Q.array[i]);
}

int main()
{
    QUEUEE* Q;
    int size;
    int ele;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    createQueue(size);
    printf("Enter an element to insert: ");
    scanf("%d", &ele);
    insertQ(Q, ele);
    display(*Q);
    return 0;
}
