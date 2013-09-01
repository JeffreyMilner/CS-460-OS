/**
 * @see README.md for compilation and usage
 */
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main( int argc, char **argv ) {
	int *A; //pointer to int
	int n; //n is the number of elements

	n = 0;
	while( n < 1 ){
		printf("Enter the number of elements for the array (positive integer...): ");
		fscanf(stdin, "%d" , &n ); //store input in n

		if( n < 1 ){
			printf("WHOAAA I SAID POSITIVE INTEGER! Please try again.\n");
		}
	}

	//allocates space for an array of n integer elements
	A = (int*) malloc( n * sizeof(int) );
	printf("Enter the elements for the array: ");
	int i;
	for( i=0; i < n; i++ ){
		scanf("%d", &A[i]);
	}
	printList( A, n );

	printf("Heapifying A[0]!\n");
	heapify( A, 0, n );
	printList( A, n );

	printf("Building the heap!\n");
	buildHeap( A, n ); //build the min-heap!
	printf("The minimum element in the heap is: %d\n", getMin( A ) );

	//print the heapified list
	printList( A, n );
	return 0;
}
