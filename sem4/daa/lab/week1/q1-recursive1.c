// Aaryan is in a treasure hunt game, there is a digital lock whose password is the single digit which is sum of digits of a number.
// If the sum of digits exceeds 9 then that new number’s digits sum is the password.To help Aaryan write a recursive C program to find the sum of digits of a number N.

#include <stdio.h>
int NumberSum(int n){
    if (n == 0){
        return 0;
    }
    else{
      int sum = n % 10 + NumberSum(n / 10);
      if (sum > 9){
          return NumberSum(sum);
      }
      else{
          return sum;
      }
    }
}

int main(){
    int n,sum;
    scanf("%d", &n);
    sum =  NumberSum(n);
    printf("%d", sum);
    return 0;
}

