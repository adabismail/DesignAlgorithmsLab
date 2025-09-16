#include <stdio.h>

//to find index of minimum element in arr[l -- r]
int findMinIndex(int arr[], int l, int r) {
    int minIndex = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Recursive selection sort
void selectionSort(int arr[], int n, int index) {
    // Base case: if we reached the end, stop
    if (index == n) return;

    //Find minimum element in subarray arr[index -- n-1]
    int minIndex = findMinIndex(arr, index, n - 1);

    //Swap with current index
    if (minIndex != index) {
        int temp = arr[index];
        arr[index] = arr[minIndex];
        arr[minIndex] = temp;
    }

    //Recurse on the remaining subarray
    selectionSort(arr, n, index + 1);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    selectionSort(arr, n, 0);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
