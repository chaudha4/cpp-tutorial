#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    char mystr[] = "abbbbbbbbbbbbbbbbbbbbabba";
    //size_t sz = sizeof(mystr) /sizeof(mystr[0]);   // why this will not work?
    size_t sz = strlen(mystr);
    printf("sz is %li\n", sz);
    
    for (size_t i = 0; i < sz; i++)
    {
        /* code */
        size_t j = sz - (i+1);
        if (i > j) {
            break;
        }

        printf("Comparing %li %c with %li %c\n", i, mystr[i], j, mystr[j]);
        if (mystr[i] != mystr[j]) {
            printf("%s is not a palindrome\n\n", mystr);
            return 0;
        }
    }
    

    printf("%s is a palindrome\n\n", mystr);
    return 1;

}