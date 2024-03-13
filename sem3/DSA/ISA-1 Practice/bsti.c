#include<stdlib.h>
#include<stdio.h>

typedef struct bsti{
    struct bsti* lchild;
    int data;
    struct bsti* rchild;
}TNODEE;

TNODEE *insert(TNODEE* root, int data){
    TNODEE* newnode;
    newnode -> data = data;
    newnode -> lchild = NULL;
    newnode -> rchild = NULL;
    TNODEE* parent_prev = NULL;
    TNODEE* child = root;
    if ( root == NULL){
        printf("heyy your bst doesnt exist!\n");
        root = newnode;
        return root;
    }
    else{
        while(child != NULL){
            parent_prev = child;
            if( child -> data < data){
                child = child -> rchild;
            }else{
                child= child -> lchild;
            }
        }
        if (parent_prev -> data > data){
                parent_prev -> lchild = data;
        }else{
                parent_prev -> rchild = data; 
        }
    }return root;
}

void preorder(TNODEE* root){
    if(root!= NULL){
        printf("%d ",root->data);
        preorder(root -> lchild);
        preorder(root -> rchild);
    }
}

void inorder(TNODEE* root){
    if(root!= NULL){
        inorder(root -> lchild);
        printf("%d ",root->data);
        inorder(root -> rchild);
    }
}

void postorder(TNODEE* root){
    if(root!= NULL){
        postorder(root -> lchild);
        postorder(root -> rchild);
        printf("%d ",root->data);

    }
}

// int count(TNODEE* root){
//     int n_lc= 0;
//     int n_rc= 0;
//     if (root != NULL){
//         n_lc = count (root-> lchild);
//         n_rc = count(root -> rchild);
//         return (n_lc + n_lc +1);
//     }
//     return 0;
// }
int count_nodes(TNODEE *root) {
  if (root == NULL) {
    return 0;
  }
  int n_left = count_nodes(root->lchild);
  int n_right = count_nodes(root->rchild);
  return n_left + n_right + 1;
}
// int leafnodes(TNODEE* root){
//     int lc=0;
//     int rc=0;
//     if (root != NULL){
//         lc= leafnodes(root -> lchild);
//         rc= leafnodes(root -> rchild);
//         return (lc + rc);
//     }
//     return 0;
// }
int leafnodes(TNODEE* root){
    if (root == NULL){
        return -1;
    }else{
        if(root -> lchild == NULL && root -> rchild == NULL){
            return 1;
        }
        else{
            return leafnodes(root -> lchild) + leafnodes(root-> rchild);
        }
    }
}
int findmin(TNODEE* root){
    if ( root == NULL){
        printf("hey, bst is empty, cant find min");
        return;
    }else{
        while(root -> lchild != NULL){
            root = root -> lchild;
        }
        printf("%d ", root -> data);
    }
}

int findmax(TNODEE* root){
    if ( root == NULL){
        printf("hey, bst is empty, cant find min");
        return;
    }else{
        while(root -> rchild != NULL){
            root = root -> rchild;
        }
        printf("%d ", root -> data);
    }
}

int search(TNODEE* root, int data){
    if(root == NULL){
        printf("empty bst-. cant search lol");
        return -1;
    }else{
        while(root!= NULL){
            if (data == root -> data){
                printf("\n haha I found youu\n");
                return 0;
            }
            else if (data > (root -> data)){
                root = root -> rchild;
            }
            else {
                root = root -> lchild;
            }
        }
    }return -1;
}

TNODEE *insucc(TNODEE* root, int ele){
    root = root -> rchild;
    while(root -> lchild != NULL){
        root = root -> lchild;
    } return (root);
}

TNODEE *deletion(TNODEE *root, int ele){
    if (root == NULL){
        return NULL;
    }
    if (ele> root -> data){
        root -> rchild = deletion(root -> rchild , ele);
    }else if(ele < root -> data){
        root -> lchild = deletion(root-> lchild, ele);
    }else{
        if(root -> rchild == NULL){
            TNODEE* temp = root -> lchild;
            free(root);
            return temp;
        }else if(root -> lchild == NULL){
            TNODEE* temp = root -> lchild;
            free(root);
            return temp;
        }else{
            TNODEE* temp = insucc(root, ele);
            root -> data = temp -> data;
            root -> rchild = deletion(root -> rchild, temp -> data);
        }
    }
}

