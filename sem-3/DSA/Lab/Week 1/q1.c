#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int maxSubarrayProduct(int nums[], int N) { 
 int maxp=nums[0];
    int rnmaxp=nums[0];
    int rnminp=nums[0];
    for(int i =1;i<N;i++){
        if(nums[i]<0){
            int tp = rnmaxp;
            rnmaxp=rnminp;
            rnminp=tp;
        }
        if(nums[i]> rnmaxp*nums[i]){
            rnmaxp= nums[i];
        }else{
            rnmaxp= rnmaxp*nums[i];
        }
        if(nums[i]< rnminp*nums[i]){
            rnminp= nums[i];
        }else{
            rnminp= rnminp*nums[i];
        }if(rnmaxp > maxp) {maxp= rnmaxp;}
        else{ maxp=maxp;}
    }return maxp;
}
int main() {
       int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int maxProduct = maxSubarrayProduct(arr, N);
    printf("%d\n", maxProduct);
    
    return 0;
}