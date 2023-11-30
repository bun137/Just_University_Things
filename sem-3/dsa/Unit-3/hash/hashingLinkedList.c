//hash table implementatin using separate chaining -> open hashing

typedef struct node{
    int data;
    struct node *next; 
}NODII;

typedef struct hashentry{
    NODII *start;
    int count;
}hashentry;

// typedef struct hashtable{
//     int size;
//     hashentry *table; //-> can be user defined data type
// }hashTable;


void insert(hashentry *ptr_t,int key, int size){
    int index = key % size;
    if(ptr_t[index].count == 0){
        ptr_t[index].start = (NODII *)malloc(sizeof(NODII));
        ptr_t[index].start->data = key;
        ptr_t[index].start->next = NULL;
        ptr_t[index].count++;
    }
    else{
        NODII *ptr = ptr_t[index].start;
        while((ptr->next) != NULL){
            ptr = ptr->next;
        }
        ptr->next = (NODII *)malloc(sizeof(NODII));
        ptr->next->data = key;
        ptr->next->next = NULL;
        ptr_t[index].count++; 
    }
}


int main(){
    hashentry *ptr_t;
    int size;
    scanf("%d",&size);
    ptr_t= calloc(size,sizeof(hashentry)); // set count to 0 and start to NULL

}