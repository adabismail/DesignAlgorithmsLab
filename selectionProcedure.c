#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int quickselect(int arr[], int l, int r, int k) {
    if (l == r) return arr[l];
    int p = partition(arr, l, r);
    int rank = p - l + 1;
    if (k == rank) return arr[p];
    else if (k < rank) return quickselect(arr, l, p - 1, k);
    else return quickselect(arr, p + 1, r, k - rank);
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("%d-th smallest element is %d\n", k, quickselect(arr, 0, n - 1, k));
    return 0;
}
