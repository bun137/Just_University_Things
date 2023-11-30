#include<stdio.h>

int min(int * t){
    int j=0;
    while(t[2*j+1]!= -1){
        j = (2*j+1);
    }
    return t[j];
}

int max(int *t){
    int k = 0;
    while(t[2*k+2]!= -1){
        k = 2*k+2;
    }
    return t[k];
}

void preorder(int *t, int i){
    if (t[i]!= -1){
        printf("%d ", t[i]);
        preorder(t, ((2*i+1)));
        preorder(t, ((2*i+2)));
    }
}

void postorder(int *t, int i){
    if (t[i]!= -1){
        postorder(t, ((2*i+1)));
        postorder(t, ((2*i+2)));
        printf("%d ", t[i]);
    }
}

void inorder(int *t, int i){
    if (t[i]!= -1){
        inorder(t, ((2*i+1)));
        printf("%d ", t[i]);
        inorder(t, ((2*i+2)));
    }
}

void insert (int *t, int key){
    int i = 0;
    while(t[i]!= -1){
        if(key > t[i]){
            i = (2*i +2);
        }
        else{
            i = (2*i+1);
        }
    }
    t[i] = key;
}

int main(){
    int arr[34];
    int i;
    int data;
    for (i= 0;i<34;i++){
        arr[i]=-1; // arr has nothing, everything is -1
    }
  while(1){
    printf("1. Insert\n");
    printf("2. Inorder\n");
    printf("3. Preorder\n");
    printf("4. Postorder\n");
    printf("5. Min\n");
    printf("6. Max\n");
    printf("0. Exit\n");
    
    printf("Enter your choice: ");
  int ch;
    scanf("%d", &ch);
  switch(ch){
    case 1:
      printf("Enter the value to be inserted: ");
      scanf("%d", &data);
      insert(arr, data);
      break;
    case 2:
      inorder(arr, 0);
      break;
    case 3:
      preorder(arr, 0);
      break;

    case 4:
      postorder(arr, 0);
      break;

    case 5:
      printf("Min: %d\n", min(arr));
      break;
    case 6: 
      printf("Max: %d\n", max(arr));
      break;

    case 0:
      return 0;
    
    default:
      printf("Invalid choice\n");
      

  }
}
  return 0;

}