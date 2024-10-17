#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *llink;
  int data;
  struct node *rlink;
} NODEE;

void insertfront(NODEE **pstart, int ele) {
  NODEE *newnode = malloc(sizeof(NODEE));
  if (*pstart == NULL) {
    *pstart = newnode;
    newnode->data = ele;
    newnode->rlink = NULL;
  } else {
    (*pstart)->llink = newnode;
    newnode->rlink = *pstart;
    *pstart = newnode;
  }
}

void insertend(NODEE **pstart, int ele) {
  NODEE *newnode = malloc(sizeof(NODEE));
  NODEE *dstart;
  newnode->data = ele;
  newnode->rlink = NULL;
  newnode->llink = NULL;

  if (*pstart == NULL) {
    *pstart = newnode;
  } else {
    (dstart) = (*pstart);
    while ((dstart)->rlink != NULL) {
      (dstart) = (dstart)->rlink;
    }
    dstart->rlink = newnode;
    newnode->llink = dstart;
  }
}

void insertpos(NODEE **pstart, int ele, int pos) {
  NODEE *newnode = malloc(sizeof(NODEE));
  newnode->data = ele;
  newnode->rlink = NULL;
  newnode->llink = NULL;
  if (*pstart == NULL) {
    *pstart = newnode;
  } else { // list is not empty
    int i = 1;
    NODEE *dstart;
    dstart = *pstart;
    while (i < pos && dstart->rlink != NULL) {
      dstart = dstart->rlink;
      i++;
    }
    if ((*pstart)->llink == NULL) { // in the first pos bc llink is null
      (*pstart)->llink =
          newnode; // use *pstart to modify, change in dstart doesnt reflect
      newnode->rlink = *pstart;
      *pstart = newnode;
    } else {
      if (i == pos) {            // checks for the range of i from 2 to L
        newnode->rlink = dstart; // change where rlink of newnode points to
        newnode->llink =
            dstart->llink; // change where llink of newnode points to
        dstart->llink =
            newnode; // changing the prev llink to point to the newnode
        dstart = newnode;
      }

      else {
        if ((i + 1) == pos) {
          dstart->rlink = newnode;
          newnode->llink = dstart;
        } else {
          printf("/n invalid pos, check pls\n");
        }
      }
    }
  }
}

void deletefront(NODEE **pstart) {
  NODEE *dstart;
  dstart = *pstart;
  if (*pstart == NULL) {
    printf("\nthere is no node to be deleted!\n");
    return;
  } else {
    if (dstart->rlink == NULL) {
      free(dstart);
      *pstart = NULL;
      return;
    } else {
      *pstart = dstart->rlink;     // *pstart =(*pstart)-> rlink
      dstart->rlink->llink = NULL; // free((*pstart)-> llink)
    }                              // (*pstart)-> llink = NULL
  }
  free(dstart);
}

void deleteend(NODEE **pstart) {
  NODEE *dstart;
  dstart = *pstart;
  if ((*pstart) == NULL) {
    printf("\nlinked list doesnt exist\n");
  } else {
    while (dstart->rlink != NULL) {
      dstart = dstart->rlink;
    }
    dstart->llink->rlink = NULL;
    free(dstart);
    dstart = NULL;
  }
}

void deleteatpos(NODEE **pstart, int pos) {
  if ((*pstart) == NULL) {
    printf("\n empty list lol -_-\n");
  } else { // list is not empty
    int i = 1;
    NODEE *dstart;
    dstart = *pstart;
    while (i < pos && dstart->rlink != NULL) {
      dstart = dstart->rlink;
      i++;
    }
    if (dstart->llink == NULL) { // 1st node
      *pstart = (*pstart)->llink;
      dstart->rlink = NULL;
      free(dstart);
      dstart = NULL;
    } else {
      if (i == pos) { // 2 to L-1
        if (dstart->rlink == NULL) {
          dstart->llink->rlink = NULL;
          dstart->llink = NULL;
          free(dstart);
          dstart = NULL;
        } else {
          dstart->llink->rlink = dstart->rlink;
          dstart->rlink->llink = dstart->llink;
          dstart->rlink = NULL;
          dstart->llink = NULL;
          free(dstart);
        }
      } else {
        printf("\ninvalid pos\n");
      }
    }
  }
}

void display(NODEE **pstart) {
  NODEE *dstart;
  dstart = *pstart;
  while (dstart != NULL) {
    printf("%d ", dstart->data);
    dstart = dstart->rlink;
  }
  printf("\n");
}

int main() {
  int ele, pos;
  int ch;
  NODEE *start;
  start = NULL;

  scanf("%d", &ch);

  while (1) {
    switch (ch) {
    case 1:
      scanf("%d", &ele);
      insertfront(&start, ele);
      display(&start);
      break;

    case 2:
      scanf("%d", &ele);
      insertend(&start, ele);
      display(&start);
      break;

    case 3:

      scanf("%d %d", &pos, &ele);
      insertpos(&start, ele, pos);
      display(&start);
      break;

    case 4:
      deletefront(&start);
      display(&start);
      break;

    case 5:
      deleteend(&start);
      display(&start);
      break;

    case 6:
      scanf("%d", &pos);
      deleteatpos(&start, pos);
      display(&start);
      break;

    default:
      printf("\nInvalid choice!\n");
      break;
    }
  }
}
