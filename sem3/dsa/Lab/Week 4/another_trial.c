#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* rlink;
    struct Node* llink;
};


struct Node* create(char* characters, int n) {
    if (n == 0) {
        return NULL;
    }

    struct Node* Head = NULL;
    struct Node* Tail = NULL;

    for (int i = 0; i < n; i++) {
        char character = characters[i];
        if (character != 'a' && character != 'e' && character != 'i' && character != 'o' && character != 'u' &&
            character != 'A' && character != 'E' && character != 'I' && character != 'O' && character != 'U') {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = character;
            newNode->rlink = NULL;

            if (Head == NULL) {
                Head = newNode;
                Tail = newNode;
                newNode->llink = NULL;
            } else {
                Tail->rlink = newNode;
                newNode->llink = Tail;
                Tail = newNode;
            }
        }
    }

    if (Head != NULL) {
        Head->llink = Tail;
        Tail->rlink = Head;
    }

    return Head;
}


void printReverse(struct Node* Head) {
    if (Head == NULL) {
        return;
    }

    struct Node* current = Head->llink;

    do {
        printf("%c", current->data);
        current = current->llink;
    } while (current != Head->llink);

    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("\n");
        return 0;
    }

    char characters[n];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &characters[i]);
    }

    struct Node* Head = create(characters, n);
    printReverseCircularDoublyLinkedList(Head);

   
    struct Node* current = Head;
    if (current != NULL) {
        do {
            struct Node* rlink = current->rlink;
            free(current);
            current = rlink;
        } while (current != Head);
    }
}