#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int ispalin(char* str, size_t idx_a) {

    size_t idx_b = strlen(str) - 1 - idx_a;
    if (idx_a >= idx_b) {
        printf("%s is a Palindrome\n", str);
        return 1;
    }

    if ( str[idx_a] ==  str[idx_b] ) {
        return ispalin(str, ++idx_a);
    }

    printf("%s is not a Palindrome", str);
    return 0;
}

int main() {

    char mystr[] = "abbbbbbbbbbbbbabbbbbbbbba";
    ispalin(mystr, 0);




    return 0;

}