#include "heap.h"

void printList(int A[], int n) {
    int ix = 0;

    printf("Elements in list: ");
    for(ix = 0; ix < n; ix++) {
        printf("%d ", A[ix]);
    }
    printf("\n");
}

void heapify(int A[], int i, int n){
    int leftChild, rightChild, newIndex, tmp;

    leftChild = 2 * (i + 1) - 1;
    rightChild = 2 * (i + 1);

    if ( leftChild <  n || rightChild < n) {
        if ( rightChild < n) {
            if ( A[leftChild] <= A[rightChild]) {
                newIndex = leftChild;
            } else {
                newIndex = rightChild;
            }
        } else {
            newIndex = leftChild;
        }

        if ( A[i] > A[newIndex]) {
            tmp = A[newIndex];
            A[newIndex] = A[i];
            A[i] = tmp;
            heapify(A, newIndex, n);
        }
    }
}

void buildHeap(int A[], int n) {
    int ix;
    for (ix = n; ix >= 0 ; ix--) {
        heapify(A, ix, n);
    }
}

int  getMin(int A[]) {
    return A[0];
}

