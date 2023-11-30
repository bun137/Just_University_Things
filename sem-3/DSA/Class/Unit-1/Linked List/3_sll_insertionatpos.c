#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtPosition(struct Node** head_ref, int data, int position) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* current = *head_ref;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Pos is out of range.\n");
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}

int main() {
    struct Node* head = NULL;
    insertAtPosition(&head, 1, 0);
    return 0;
}