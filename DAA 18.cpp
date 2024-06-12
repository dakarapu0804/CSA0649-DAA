#include <stdio.h>

int isPrime(int n, int i) {
    if (i == 1) {
        return 1; // 1 is not a prime number
    }
    if (n <= 2) {
        return 1; // 2 is a prime number
    }
    if (n % i == 0) {
        return 0; // not a prime number
    }
    if (i * i > n) {
        return 1; // prime number
    }
    return isPrime(n, i + 1); // recursive call
}

void generatePrimes(int n) {
    int i;
    for (i = 2; i <= n; i++) {
        if (isPrime(i, 2)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d are: ", n);
    generatePrimes(n);
    return 0;
}
