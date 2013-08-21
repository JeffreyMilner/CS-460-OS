#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int leftChildIndex( int index ){
	return 2 * ( index + 1 ) - 1;
}

int rightChildIndex( int index ){
	return 2 * ( index + 1 );
}

void heapify( int A[], int index, int len ){
	int leftChild, rightChild, newIndex, swapVal;

	leftChild = leftChildIndex( index );
	rightChild = rightChildIndex( index );
	//test if left/right child exists
	if( leftChild < len || rightChild < len ){
		//since child exists swap index with lowest child
		if( rightChild < len ){
			newIndex = A[leftChild] <= A[rightChild] ? leftChild : rightChild;
		}else{
			newIndex = leftChild;
		}
		swapVal = A[newIndex];
		A[newIndex] = A[index];
		A[index] = swapVal;
		//then run heapify on newly updated index
		heapify( A, newIndex, len );
	}
	//else noop (we are done with this heapify)
};

void buildHeap( int A[], int len ){

};

int getMin( int A[] ){
	return A[0];
};



void printList( int A[], int n ){
	printf("Elements in the list: ");
	int i;
	for( i=0; i < n; i++ ){
		printf("%d ", A[i] );
	}
	printf("\n");
};
