#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void reverseWords(char* s) {
    char line[512];
    char* word;
    char* wordss[256];
    int counter = 0;

    scanf("%[^\n]s", line);

    word = strtok(line, " ");
    while (word != NULL) {
        wordss[counter] = word;
        counter++;
        word = strtok(NULL, " ");
    }
    for (int i = counter - 1; i >= 0; i--) {
        printf("%s ", wordss[i]);
    }

}

int main() {
    char str[512];
    //int counter = 0; 
   // char* wordss[256];
    reverseWords(str);
    
    return 0;
}
