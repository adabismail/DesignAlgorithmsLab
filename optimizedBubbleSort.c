#include <stdio.h>
#include <stdbool.h>

void optimizedBubbleSort(int a[], int n) {
    if (n <= 1) return;

    for (int pass = 0; pass < n - 1; ++pass) {
        bool swapped = false;
        for (int j = 0; j < n - pass - 1; ++j) {
            if (a[j] > a[j + 1]) {
                //swapping
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}


void printArray(int a[], int n) {
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
}


int main(void) {
    int a[] = {5, 1, 4, 2, 8};      
    int b[] = {1, 2, 3, 4, 5};        
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    printf("Original a: ");
    printArray(a, n);
    optimizedBubbleSort(a, n);
    printf("Sorted   a: ");
    printArray(a, n);

    printf("Original b: ");
    printArray(b, m);
    optimizedBubbleSort(b, m);
    printf("Sorted   b: ");
    printArray(b, m);

    return 0;
}
