#include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // choosing the last element as pivot
    int i = low - 1;         // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;             // move boundary for smaller elements
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // place pivot in correct position
    return (i + 1); // return pivot index
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find partition index
        int pi = partition(arr, low, high);

        // Recursively sort left and right halves
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Driver code
int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

