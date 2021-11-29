
// rm ./a.out; gcc 020-bad-coding.c; ./a.out



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getName1() {
    char name[] = "Abhishek";
    return name;
}

char* getName2() {
    char* name = "Abhishek";
    return name;
}

char* getName3() {
    char* ret;
    strcpy(ret, "Abhishek");
    return ret;
}

char* getName4() {
    char* name = "Abhishek";
    char* ret = (char*) malloc(sizeof(name));
    strcpy(ret, "Abhishek");
    return ret;
}

// Driver Code
void main(void) {
    printf("test started\n");

    printf("%s\n", getName4());


    printf("test ended\n");
    return;
}