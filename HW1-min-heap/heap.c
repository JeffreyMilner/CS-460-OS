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
		//since child exists swap index with lowest child if child has lower value
		if( rightChild < len ){
			newIndex = A[leftChild] <= A[rightChild] ? leftChild : rightChild;
		}else{
			newIndex = leftChild;
		}
		//Only swap if child is lower value
		if( A[index] > A[newIndex] ){
			swapVal = A[newIndex];
			A[newIndex] = A[index];
			A[index] = swapVal;
			//then run heapify on newly updated index
			heapify( A, newIndex, len );
		}
	}
	//else noop (we are done with this heapify)
};

void buildHeap( int A[], int len ){
	//Hint: nodes without children satisfy the min-heap property
	//^^^ Made it too easy. Just work in reverse order of the heap array
	//since the last element starts as a trivial min-heap, and thus every climb up
	// the array will therefore be a min-heap if 'heapified'.
	int i;
	for( i = len; i >= 0; i-- ){
		heapify( A, i, len );
	}
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
