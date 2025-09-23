#include <stdio.h>

void strassen(int a[2][2], int b[2][2], int c[2][2]) {

    int p1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    int p2 = (a[1][0] + a[1][1]) * b[0][0];
    int p3 = a[0][0] * (b[0][1] - b[1][1]);
    int p4 = a[1][1] * (b[1][0] - b[0][0]);
    int p5 = (a[0][0] + a[0][1]) * b[1][1];
    int p6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    int p7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);


    c[0][0] = p1 + p4 - p5 + p7;
    c[0][1] = p3 + p5;
    c[1][0] = p2 + p4;
    c[1][1] = p1 - p2 + p3 + p6;
}

void printMatrix2x2(int mat[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[2][2] = { 
                       {1, 2}, 
                       {3, 4} 
                    };
    int mat2[2][2] = { 
                       {5, 6}, 
                       {7, 8} 
                    };
    int res[2][2];

    strassen(mat1, mat2, res);

    printf("Result matrix is:\n");
    printMatrix2x2(res);

    return 0;
}