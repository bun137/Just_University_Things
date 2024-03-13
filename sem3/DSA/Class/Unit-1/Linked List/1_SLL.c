#include <stdio.h>
#include <string.h>

int insertfront(sll_node **pstart, int ele)
{
    sll_node *newnode;
    newnode = (sll_node *)malloc(sizeof(sll_node));

    if (newnode == NULL)
    {
        return 0;
    }
    else
    {
        if (*pstart != NULL)
            newnode->link = *pstart;
        (*pstart) = newnode;
        return 1;
    }
}
void deleteback()
{
    sll_node *newnode;
    newnode = malloc();
    if (!newnode)
    {
        printf("empty list lol");
        return 0;
    }
    else
    {
        if(*pstart -> link ==NULL){
            printf("you have one node only in the linked list");
            free(*pstart);
            *pstart = NULL;
        }
    while(*pstart->link!= NULL){
        *pstart = *pstart -> link;
    }
    free(*pstart->link);
    *pstart->link = NULL;
}
    }

void insertback()
{
    sll_node *newnode;
    newnode = (sll_node *)malloc(sizeof(sll_node));

    if (newnode == NULL)
    {
        return 0;
    }
    else
    {
        if (*pstart == NULL)
        {
            *pstart = newnode;
        }
        else
        {
            sll_node *dstart;
            dstart = *pstart;
            while ((dstart->link) != NULL)
            {
                dstart = (dstart->link);
            }
            (dstart->link) = newnode;
        }
    }
}

int insert_at_pos(){
    int pos,data=56;
    printf("Enter the position to be inserted : ");
    scanf("%d",&pos);
    if (pos == 1){
        insertfront()
    }
    else
        {
            
            sll_node *dstart;
            dstart = *pstart;
            if(pos==1){
                insertfront();
            }
            else{
                sll_node *dstart,*prev;
                start = *pstart;
                int i = 1;
                    while((dstart->link)!=NULL && i<pos  ){
                        dstart =(dstart -> link );
                        ++i;            
                        prev = dstart;                    
                    }
                    if(i==pos){
                        prev->link = newnode;
                        newnode->link =dstart;                        
                    }
                    else{
                        if(i+1==pos){
                            prev->link =newnode;
                            newnode->link = NULL ;
                        }
                        else{
                            printf("\nInvalid Position\n");
                            return 0;
                        }
                }            
            }
        }
    return 1;
}

sll_node * delete_front(sll_node *start){
    if(start!=NULL){
        return NULL;
    }else{
        dstart = start;
        start=start->link;
    }
free(dstart);
return start;

}



void deleteNode(struct Node *pstart, int pos) {
    if (*pstart == NULL) {
        return 0;
    }

    struct Node *prev =*pstart;
    for (int i = 0; i < pos - 1; i++) {
        prev = prev->next;
    }
    if (prev ==*pstart) {
     *pstart = *pstart>next;
    } else {
        prev->link = prev->link->link;
    }

    free(prev->link);
}
 void delelte_node_with_key(){
    struct node* temp = *pstart,*prev;

    if(temp! = NULL && temp ->link ==key){
        *pstart = temp ->link;
        free(temp);
        return 0;
    }
    if(temp! = NULL && temp ->link !=key){
        prev = temp;
        temp = temp ->link;
    }
    if( temp ==  NULL){
        prev->link = temp ->link;
        free(temp);
    }
 }
    void concatenate(struct Node* a, struct Node* b) {
    // if (a != NULL && b != NULL) {
    //     if (a->link == NULL)
    //         a->link = b;
    //     else
    //         concatenate(a->link, b);
    // } else {
    //     printf("Either a or b is NULL\n");
    // }
}

void merge_2_sll(){
    int n=sizeof(arr)/ sizeof(*arr),i ;
    struct Node** arr[n];
    for(i=0;i<n;++i ){
        arr[i] =(struct Node*)malloc(sizeof(struct Node));
        arr[i]->data = i+1;
}

int main() {
        deleteNode(head, 2);
        return 0;
}