/**
 * @file 002-dynamic-array.c
 * @author your name (you@domain.com)
 * @brief Example of creating and then returning that array from a function
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */


// rm ./a.out; gcc 002-dynamic-array.c; ./a.out

#include <stdio.h>
#include <stdlib.h>


int create_arr(int** const arr1, const size_t num) {

    printf("Entering create_arr\n");

    //Use %p to print pointer
    printf("%p\t%p\n", arr1, *arr1);

    // changes to *arr1 will also be seen by the caller.
    // changes to arr1 will not be seen by the caller.
    *arr1 = (int*) malloc(sizeof(int) * num);
    printf("%p\t%p\n", arr1, *arr1);
    
    //(*arr1)[9] = 326587;

    
    for (size_t i = 0; i < num; i++)
    {
        (*arr1)[i] = i;
    }
    

    printf("\nCreated \t");
    
    for (size_t i = 0; i < num; i++)
    {
        printf("%d-", (*arr1)[i]);
    }
    
    return num;
}


void main() {
    printf("Start\n");
    int* arr1;
    printf("%p\t%p\n", &arr1, arr1);
    create_arr(&arr1, 10);
    
    printf("\nCreated \t");
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d-", arr1[i]);
    }
    printf("\n");
    return;
}



