#include<stdio.h>
#include<stdlib.h> 
// TO DO INCOMPLETE-
typedef struct polynode {
    int co;
    int exp;
    struct polynode *ptr_to_next;
} poly_node;

void attach(int c, int e, poly_node **ptr_to_start) {
    poly_node *temp, *rear;
    temp = (poly_node *)malloc(sizeof(poly_node));
    temp->co = c;
    temp->exp = e;
    temp->ptr_to_next = NULL;
    
    if (*ptr_to_start == NULL) {
        *ptr_to_start = temp;
    } else {
        rear = *ptr_to_start;
        while (rear->ptr_to_next != NULL) {
            rear = rear->ptr_to_next;
        }
        rear->ptr_to_next = temp;
    }
}

poly_node *readpoly() {
    poly_node *start = NULL;
    int c, e;
    int terms = 1;
    while (terms) {
        printf("Enter coef and exp: ");
        scanf("%d %d", &c, &e);
        attach(c, e, &start);
        printf("Do you have any more terms? enter 1 for y, 0 for n: ");
        scanf("%d", &terms);
    }
    return start;
}

void display_poly(poly_node *head) {
    while (head != NULL) {
        printf("%d", head->co);
        if (head->exp > 0) {
            printf("x^%d", head->exp);
        }
        head = head->ptr_to_next;
        if (head != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    poly_node *poly = readpoly();
    printf("Polynomial: ");
    display_poly(poly);
    
    return 0;
}
