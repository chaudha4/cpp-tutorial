#include <stdio.h>
#include <string.h>

// rm ./a.out; gcc 010-palindrome.c; ./a.out

int ispalindrome(char* str, int x) {
    int len = strlen(str) - 1;  // make it zero based since x is zero based
    printf("\nThe string size is %i and x is %i", len+1, x);
    
    if (len/2 == x) {
        if (len%2 == 0) {
            printf("\nReached middle");
            return 1;
        } else {
            printf("\nReached middle two");
            if (str[x] == str[len-x]) {
                return 1;
            }
            return 0;
        }
    }

    // Compare the x and last-x. Call recursively for the rest
    if (str[x] == str[len-x]) {
        return ispalindrome(str, ++x);
    }

    return 0;
}

int main() {
    printf("\n");
    char mystr[] = "bababsss";
    printf("\n Ans is %i\n", ispalindrome(mystr, 0));

/**
    printf("%li", sizeof(mystr));
    printf("%li", sizeof(*mystr1));
    printf("\n");
    printf("%s\n", mystr);
    printf("%s\n", mystr1);
    printf("%c - %c - %c\n", mystr1[0], mystr1[7], mystr1[8]);

    for (size_t i = 0; i < sizeof(mystr); i++)
    {
        printf("%c - ", mystr[i]);
    }
    printf("\n");
    for (size_t i = 0; i < strlen(mystr1); i++)
    {
        printf("%c - ", *(mystr1 + i));
    }
*/    
    printf("\n");

    printf("\n");
}