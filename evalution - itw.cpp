#include <stdio.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify operation to maintain Min-Heap property
void heapify(int arr[], int n, int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // If right child is smaller than the smallest so far
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If smallest is not root, swap and continue heapifying
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Function to build a Min-Heap from an unsorted array
void buildMinHeap(int arr[], int n) {
    // Start from the last non-leaf node and apply heapify
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to print the heap
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 10, 3, 5, 1}; // Example array to build Min-Heap
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printHeap(arr, n);

    // Build Min-Heap
    buildMinHeap(arr, n);

    printf("Min-Heap: ");
    printHeap(arr, n);

    return 0;
}