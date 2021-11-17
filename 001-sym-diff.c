/**
 * @file 001-sym-diff.c
 * @author Abhishek Chaudhary
 * @brief https://www.freecodecamp.org/learn/coding-interview-prep/algorithms/find-the-symmetric-difference
 * @version 0.1
 * @date 2021-11-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>


// rm ./a.out; gcc 001-sym-diff.c; ./a.out

// Utility to print array
int parray(int arr[], size_t len) {
    printf("\n");
    
    // Why can't you calculate length doing this ? You cannot
    // int len = sizeof(arr) / sizeof(arr[0]);
    // Read https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters/

    for (int ii = 0; ii < len; ii++) {
        printf("%d\t",arr[ii]);
    }
    printf("\n");
    return 0;
}


//int sym_diff(int arr1[], size_t len1, int arr2[], size_t len2, int** response) {
int* sym_diff(int* arr1, size_t len1, int* arr2, size_t len2, int* res_size) {    
    parray(arr1, len1);
    parray(arr2, len2);

    size_t found_diff  = 0;
    int asterix = 0;
    int asterix_count = 2;  // first match in both arrays. So start with 2.

    for (size_t ii = 0; ii < len1; ii++) {
        for (size_t jj = 0; jj < len2; jj++) {
            if (arr1[ii] == arr2[jj]) {
                if (!found_diff) {
                    asterix = arr1[ii];
                    found_diff=1; // Atleast one match between two arrays
                }

                if (arr1[ii] != asterix) {
                    arr1[ii] = asterix; // replace the number with asterix.
                    asterix_count++;
                }
                if (arr2[jj] != asterix) {
                    arr2[jj] = asterix; // replace the number with asterix.
                    asterix_count++;
                }
            }            
        }
    }

    // Array that is now updated with matching numbers asterixed.
    parray(arr1, len1);
    parray(arr2, len2);
    printf("There are %i duplicates found\n", asterix_count);    
    
    // Now we have to return one array with all non matching numbers.
    int new_size = len1 + len2 - asterix_count;

    // Dynamically allocate memory using malloc(). 
    int *retarr = (int*) malloc(new_size * sizeof(int));

    // Why can't we do this instead of malloc ??
    // int retarr[new_size];
    // Because this will cause memory corruption
    // https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/


    int index = 0;
    for (int ii = 0; ii < len1; ii++) {
        if (arr1[ii] != asterix) {
            retarr[index++] = arr1[ii];
        }
    }

    for (int ii = 0; ii < len2; ii++) {
        if (arr2[ii] != asterix) {
            retarr[index++] = arr2[ii];
        }
    }

    parray(retarr, new_size);

    // Save the response pointer to the passed location
    *res_size = new_size;
    //parray(**response, new_size);

    return retarr;

}


int main() {

    printf("sym([1, 2, 3], [5, 2, 1, 4]) should return [3, 4, 5]\n");
  
    int arr1[] = {1, 2, 3};
    int arr2[] = {5, 2, 1, 4};

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int *resp_len;
    int *resp = sym_diff(arr1, len1, arr2, len2, resp_len);

    parray(resp, *resp_len);

    // free the memory - We own the memory 
    free(resp);

    return 0;
}