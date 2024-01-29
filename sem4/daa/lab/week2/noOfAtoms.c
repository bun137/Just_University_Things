// Find the sum of atoms in the given chemical comp
//
// If the element is simply given, it is one atom, else the number following it
// gives the number of atoms Molecules can be enclosed in parentheses, which
// have to be counted with the number given outside the parentheses eg (SO3)2
// The element name always starts with a capital letter and is followed by a
// small letter Input Format
//
// a single string of chemical comp
//
// Constraints
//
// the comp should be of size <=20
// the digit denoting the number of atoms should be a single digit (2 to 9)
// assume the string is always valid
// Output Format
//
// A single integer denoting the sum of atoms
#include <stdio.h>
#include <stdlib.h>

typedef struct stackelement {
  int num;          // current count
  char parentheses; // open and closed parentheses
} SE;

int atoms_sum(char comp[]) {
  SE stack[20];
  int stkptr = -1;
  int res = 0;
  int i = 0;
  while (comp[i] != '\0') {
    if (comp[i] >= 'A' && comp[i] <= 'Z') {
      res++;
      i++;
    } else if (comp[i] >= 'a' && comp[i] <= 'z') {
      i++;
    } else if (comp[i] >= '2' && comp[i] <= '9') {
      int count = comp[i] - '0';
      while (comp[i + 1] >= '0' && comp[i + 1] <= '9') {
        count = count * 10 + (comp[i + 1] - '0');
        i++;
      }
      res += count - 1;
      i++;
    } else if (comp[i] == '(') {
      stkptr++;
      stack[stkptr].num = res;
      stack[stkptr].parentheses = '(';
      res = 0;
      i++;
    } else if (comp[i] == ')') {
      int a = 1;
      if (comp[i + 1] >= '0' && comp[i + 1] <= '9') {
        a = comp[i + 1] - '0';
        i++;
      }
      res *= a;
      res += stack[stkptr].num;
      stkptr--;
      i++;
    }
  }
  return res;
}

int main() {
  char comp[21];
  scanf("%s", comp);
  printf("%d\n", atoms_sum(comp));

  return 0;
}
