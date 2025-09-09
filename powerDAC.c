#include <stdio.h>

long long power(int a, int b) {

    if (b == 0) 
        return 1;
    if (b == 1)
        return a;
    long long half = power(a, b / 2);

    if (b % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}

int main() {
    int base, exponent;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    long long result = power(base, exponent);
    printf("%d^%d = %lld\n", base, exponent, result);

    return 0;
}
