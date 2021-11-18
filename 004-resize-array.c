#include <stdio.h>
#include <stdlib.h>


// rm ./a.out; gcc 004-resize-array.c; ./a.out

int main() {

    int* arr = (int*) malloc(2 * sizeof(int));
    *arr = 10;
    *(arr+1) = 11;

    printf("\n%d - %d\n", arr[0], arr[1]);

    printf("\n%i", sizeof(arr));
    
    // resize the array
    arr = realloc(arr, 4 * sizeof(int));
    
    printf("\n%i", sizeof(arr));


    // Add 2 more elements
    *(arr+2) = 14;
    *(arr+3) = 1167;

    printf("\n");
    for(int ii=0; ii<4; ii++) {
        printf("%d - ", arr[ii]);
    }
    

    printf("\nEnd\n");

}