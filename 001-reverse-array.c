/**
 * @file 004-reverse-array.c
 * @author your name (you@domain.com)
 * @brief Program to print the reverse of an Array
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// rm ./a.out; gcc 001-reverse-array.c; ./a.out

#include <stdio.h>

#define LEN(x) sizeof(x)/sizeof(x[0])

int printreverse(const int arr[], size_t len) {
    printf("\n");
    for (int ii=len-1; ii>=0; ii-- ) {
        printf("%d,", arr[ii]);
    }
    printf("\n");
}

int main() {
    printf("\nStart\n");
    int arr1[] = {22, 11, 33, 3, 6, 88, 99};
    printreverse(arr1, LEN(arr1));
}