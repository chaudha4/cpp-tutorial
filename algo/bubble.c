#include <stdio.h>

//  gcc -Wall bubble.c -o app; ./app

void printarr(int arr[], int len) {
	int ii;
	for (ii=0; ii<len; ii++) {
		printf("-%i",arr[ii]);
	}
	printf("\n");
	return;
}


void bubblesort(int arr[], int len) {

	int ii, jj;
	for (ii=0; ii<len; ii++) {
		for (jj=0; jj<len-ii-1; jj++) {
			if ( arr[jj] > arr[jj+1] ) {
				int temp = arr[jj];
				arr[jj] = arr[jj+1];
				arr[jj+1] = temp;
				printarr(arr,len);
			}
		}
		printarr(arr,len);
	}
	printarr(arr,len);

	return;
}


int main (void) {
	printf("Hello World\n");
	int arr[] = {79,23,33,44,2,1,67};
	bubblesort(arr,7);
	return 0;
}
 
