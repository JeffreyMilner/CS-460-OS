#include "heap.h"

int main(int argc, const char *argv[]) {
    int *A; // Pointer to int
    int n; // n is the number of elements

    printf("Enter the number of elements for the array: ");
    fscanf(stdin, "%d", &n);

    // Allocate space for an array of n integer elements
    A = (int*) malloc(n * sizeof(int));

    // Get values for A from user
    int ix;
    for(ix = 0; ix < n; ix++) {
        scanf("%d", &A[ix]);
    }

    printList(A, n);

    printf("Heapifying A[0]!\n");
    heapify(A, 0, n);
    printList(A, n);

    printf("Building the heap!\n");
    buildHeap(A, n); // Build the min-heap
    printf("The minimum element in the heap is: %d\n", getMin(A));

    // Print the heapified list
    printList(A, n);

    return 0;
}
