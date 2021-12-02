/**
 * @file 000-practice.c
 * @author Abhishek Chaudhary
 * @brief TO run - rm ./a.out; gcc 000-practice.c; ./a.out
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// rm ./a.out; gcc 000-practice.c; ./a.out

#include <stdio.h>

#define LEN(x) sizeof(x) / sizeof(x[0])

int main() {
    
    int arr1[] = {10, 9, 11, 1};

    int ll = LEN(arr1);
     for (size_t i = 0; i < ll; i++)
     {
         printf("%i\t", arr1[i]);
         for (size_t j = 0; j <  ll; j++)
         {
             if ( arr1[i] <  arr1[j] ) {
                 int kk = arr1[i];
                 arr1[i] = arr1[j];
                 arr1[j] = kk;
             }
         }
         
     }
     
    printf("\n");
    for (size_t i = 0; i < ll; i++)
    {
        printf("%i\t", arr1[i]);
    }
    printf("\n");


}