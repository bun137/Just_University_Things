/* An adventurer has landed upon a hidden treasure in an ancient city of Algoria. 
The code to unlock the treasure is sequence of numbers that has been rotated once. 
Your task is to write a C program to check if a specific target number that the adventurer 
has in his mind, is present or not in this twisted array of code using the concept of binary search. 
The code array was originally sorted in non-decreasing order but has been rotated now. 
Complete the function ‘searchForNumber’ that takes the rotated array of distinct integers of size N,
and target number T. If the target number is found in the array, the program should say
“yes, found at index_number” else it should say “no”. */

#include <stdio.h>

int searchArray(int arr[], int smallest, int largest, int target){
 if(smallest > largest){
   return -1;
 }

 int middle = (smallest + largest) / 2;

 if (arr[middle] == target){
   return middle;
 }

 if(arr[smallest] <= arr[middle]){
   if(target >= arr[smallest] && target <= arr[middle]){
     return searchArray(arr, smallest, middle - 1, target);
   }
   return searchArray(arr, middle + 1, largest, target);
 }

 if(target >= arr[middle] && target <= arr[largest]){
   return searchArray(arr, middle + 1, largest, target);
 }

 return searchArray(arr, smallest, middle - 1, target);
}

int main(){
    int n, target;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target);
    int index = searchArray (arr, 0, n - 1, target);
    if (index == -1){
        printf("No");
    }
    else{
        printf("Yes, found at %d", index);
    }
    return 0;
}

