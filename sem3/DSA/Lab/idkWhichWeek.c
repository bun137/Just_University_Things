#include <stdio.h>
#include <string.h>
typedef struct {
    int ucode;
    char name[20];
} details;
details lpTable[30];
details qpTable[30];
int lp(int hash, int size, int trial) {
    return (hash + trial) % size;
}

int qp(int hash, int size, int trial) {
    return (hash + trial * trial) % size;
}
void inserti(details* table, int ucode, const char *name, int size, int probing) {
    int hash = ucode % size;
    int i = hash;
    int trial = 0;

    while (table[i].ucode != 0 && trial < size) {
        if (probing == 1) {
            i = lp(hash, size, ++trial);
        } else if (probing == 2) {
            i = qp(hash, size, ++trial);
        }
    }
    if (trial < size) {
        table[i].ucode = ucode;
        strcpy(table[i].name, name);
    }
}
void deletedetails(details* table, int ucode, int size, int probing) {
    int hash = ucode % size;
    int i = hash;
    int trial = 0;

    while (table[i].ucode != ucode && table[i].ucode != 0 && trial < size) {
        if (probing == 1) {
            i = lp(hash, size, ++trial);
        } else if (probing == 2) {
            i = qp(hash, size, ++trial);
        }
    }

    if (table[i].ucode == ucode) {
        table[i].ucode = 0;
    }
}
void display(details *table, int size) {
    for (int i = 0; i < size; i++) {
        if (table[i].ucode != 0) {
            printf("%d %s\n", i+1, table[i].name);
        }
    }
}
int main() {
    int n, numOps;
    scanf("%d %d", &n, &numOps);

    for (int i = 0; i < numOps; i++) {
        int operation, ucode;
        char name[100];
        scanf("%d", &operation);

        if (operation == 1) {
            scanf("%d %s", &ucode, name);
            inserti(lpTable, ucode, name, n, 1);
            inserti(qpTable, ucode, name, n, 2);
        } else if (operation == 2) {
            scanf("%d", &ucode);
            deletedetails(lpTable, ucode, n, 1);
            deletedetails(qpTable, ucode, n, 2);
        }
    }
    display(lpTable, n);
    printf("\n");
    display(qpTable, n);
    return 0;
}