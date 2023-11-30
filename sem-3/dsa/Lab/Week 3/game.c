#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* rlink;
    struct Node* llink;
} NODEE;

struct Node* createNode(int data) {
    NODEE *newnode = malloc(sizeof(NODEE));
    newnode->rlink = NULL;
    newnode->llink = NULL;
    newnode->data = data;
    return newnode;
}

void insertNodeAtEnd(NODEE **pstart, int data) {
    NODEE * newnode = createNode(data);
    NODEE *dstart;
    dstart = *pstart;
    
    if(*pstart == NULL){
        *pstart = newnode;
    }
    else{
        (dstart) = (*pstart);
        while((dstart) -> rlink != NULL ){
            (dstart)= (dstart) -> rlink;
        }
        dstart -> rlink = newnode;
        newnode -> llink = dstart;
    }
}

int playGame(struct Node** head) {
  int skips,score;
    score=0;
    NODEE* dhead;
    NODEE* todel;
    dhead = *head;
    while(dhead != NULL){
        skips = dhead -> data;
        todel = dhead;
        if(skips > 0){
            score +=skips;
        }else{
            score = score;
        }

        if(skips>=0){
            for(int i=0; i<=skips; i++){
                
                dhead=dhead->rlink; 
                if(dhead== NULL){
                    return score;
                }
                

            }   
        }else{
            for(int i=0; i>=skips; i--){
                dhead=dhead->llink; 
                if(dhead== NULL){
                    return (-score);
                }
                

            }   
        }
        if (todel -> llink == NULL){
            todel -> rlink -> llink = NULL;
            free(todel);
      
        }else if(todel -> rlink == NULL){
            todel -> llink -> rlink = NULL;
            free(todel);
        }else{
        todel-> llink->rlink= todel ->rlink;
        todel->rlink->llink = todel -> llink;}
        
    }
    return score;
}

int solve() {
int n, num;
    scanf("%d", &n);
    NODEE* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insertNodeAtEnd(&head, num);
    }
    int result = playGame(&head);
    return result;
}

// Driver code
int main() {
    
    int score = solve() ;
    printf("%d", score) ;
    return 0;
}