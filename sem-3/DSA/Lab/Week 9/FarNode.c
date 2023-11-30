#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct alist {
    struct node* head;
};
struct Graph {
    int V;
    struct alist* array;
};
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct alist*)malloc(V * sizeof(struct alist));
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}
void MakeEdge(struct Graph* graph, int src, int dest) {
    struct node* newnode = createnode(dest);
    newnode->next = graph->array[src].head;
    graph->array[src].head = newnode;
    newnode = createnode(src);
    newnode->next = graph->array[dest].head;
    graph->array[dest].head = newnode;
}
int bfs(struct Graph* graph, int startnode) {
    int* v = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        v[i] = 0;
    }
    int fn = startnode;
    int fd = 0;
    int* q = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;
    v[startnode] = 1;
    q[rear++] = startnode;
    while (front < rear) {
        int currnode = q[front++];
        struct node* temp = graph->array[currnode].head;
        while (temp != NULL) {
            int adjacentnode = temp->data;
            if (!v[adjacentnode]) {
                v[adjacentnode] = 1;
                q[rear++] = adjacentnode;
                if (fd + 1 > fd) {
                    fn = adjacentnode;
                    fd++;
                }
            }
            temp = temp->next;
        }
    }

    free(v);
    free(q);
    return fn;
}

int solve(){
	int n, e;
    scanf("%d %d", &n, &e);

    if (n == 0 || e == 0) {
        return -1;
    }
    struct Graph* graph = createGraph(n);

    for (int i = 0; i < e; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        MakeEdge(graph, n1 - 1, n2 - 1);
    }
    int startnode;
    scanf("%d", &startnode);
    startnode--; 
    int fn = bfs(graph, startnode);
    free(graph->array);
    free(graph);
    return fn + 1; 
}
int main() {
    printf("%d",solve());
    return 0;
}