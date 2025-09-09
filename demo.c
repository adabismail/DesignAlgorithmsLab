#include <stdio.h>

int power(int base, int exponent){
    int result = 1;
    for (int i=0; i<exponent; i++){
        result *= base;
    }
    return result;
}

int main() {
    printf("Hello, World!\n");
    int a = 5;
    int b = 3;

    int result = power(a, b);
    printf("%d to the power of %d is %d\n", a, b, result);
}