#include <stdio.h>
#include <stdlib.h>

typedef struct queues {
  struct queues *front;
  struct queues *rear;
  int data;
  int capacity;
  int count_curr_size;
  int *arr;
} QUEUEE;

QUEUEE *createQueue(int capacity) {
  QUEUEE *queue = (QUEUEE *)malloc(sizeof(QUEUEE));
  queue->capacity = capacity;
  queue->front = NULL;
  queue->rear = NULL;
  queue->arr = (int *)malloc(queue->capacity * sizeof(int));
  return queue;
}

int isEmpty(QUEUEE *Q) { return Q->front == NULL; }

int isFull(QUEUEE *Q) { return Q->count_curr_size == Q->capacity; }

int insertQ(QUEUEE *Q, int item) {
  if (isFull(Q)) {
    printf("Queue is full\n");
    return -1;
  }

  QUEUEE *newNode = (QUEUEE *)malloc(sizeof(QUEUEE));
  newNode->data = item;
  newNode->front = NULL;

  if (isEmpty(Q)) {
    Q->front = newNode;
    Q->rear = newNode;
  } else {
    Q->rear->front = newNode;
    Q->rear = newNode;
  }

  Q->count_curr_size++;
  printf("Enqueued %d\n", item);
  return 0;
}

int deletefront(QUEUEE *Q) {
  if (Q->front == NULL) {
    printf("Queue is empty\n");
    return -1;
  }

  QUEUEE *temp = Q->front;
  int item = temp->data;

  Q->front = Q->front->front;
  free(temp);

  if (Q->front == NULL) {
    Q->rear = NULL;
  }

  Q->count_curr_size--;
  printf("Dequeued %d\n", item);
  return item;
}

int main() {
  QUEUEE *Q = createQueue(5);
  Q->count_curr_size = 0; // Initialize the count_curr_size member
  insertQ(Q, 1);
  insertQ(Q, 2);
  insertQ(Q, 3);
  insertQ(Q, 4);
  insertQ(Q, 5);
  insertQ(Q, 6);
  deletefront(Q);
  return 0;
}
