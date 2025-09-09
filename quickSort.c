#include <stdio.h>

/* Swap two integers by pointer */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Partition using Lomuto partition scheme */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // choose last element as pivot
    int i = low - 1;          // place for the smaller element
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* QuickSort recursive function */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Utility to print array */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Example main: reads n, then n numbers, sorts and prints */
int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Failed to read size\n");
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Failed to read array element %d\n", i);
            return 1;
        }
    }

    printf("Before sort: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("After sort:  ");
    printArray(arr, n);
    return 0;
}
