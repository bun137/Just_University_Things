#include <stdio.h>
#include <stdlib.h>

int* twoSum(int arr[], int arr_size, int target, int* result_size, int arr1[]){
    
    int *size =0;
    int i = 0;
    for (i = 0; i < arr_size; i++) {  
        for (int j=i+1; j<arr_size;j++){
        if (arr[j] + arr[i] == target) {
            *size++;
            
            printf("Target found at index %d: %d :%d\n", i, arr[i], arr[j]);
            arr1[0]= arr[i*2 -2];
            arr1[1]= arr[i*2 -1];
        }
    }} return arr1;
}
int main() {
    int i = 0;
    int counter = 0;
    int target = 9;
    int size = 0;
    int arr1[10];
    int arr[] = { 5 ,7 ,2, 8, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);  
    int* arr1 = twoSum(arr, arr_size, target, &size,);

      for (i = 0; i < size; i++) {
        printf("[%d, %d]\n", arr1[i * 2], arr1[i * 2 + 1]);
    }
    free(arr1);
    
   
}

    
    