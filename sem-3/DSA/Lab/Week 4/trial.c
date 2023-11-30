#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode->prev = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

int isVowel(char c) {
    c = tolower(c); 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


void removeVowels(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* current = *head;
    do {
        if (isVowel(current->data)) {
            struct Node* temp = current;
            if (current == *head) {
                *head = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
    } while (current != *head);
}

void printReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* current = head->prev;
    do {
        printf("%c", current->data);
        current = current->prev;
    } while (current != head->prev);
}

int main() {
    int n;
    scanf("%d", &n);
    char input;
    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        scanf(" %c", &input);
        insertEnd(&head, input);
    }

    removeVowels(&head);

    printReverse(head);

    return 0;
}
