#include <stdio.h>

int main() {
    int i = 0;
    int counter = i+1;
    int target = 9;
    int arr[] = {2, 5, 7, 8, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);  
    for (i = 0; i < arr_size; i++) {  
        if (counter + arr[i] == target) {
            printf("Target found at index %d: %d :%d\n", i, arr[i], counter);
        }
        counter++;
    }

    return 0;
}