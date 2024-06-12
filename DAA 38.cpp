#include <stdio.h>

void findFactors(int n, int i) {
    if (i > n) {
        return;
    }
    if (n % i == 0) {
        printf("%d ", i);
    }
    findFactors(n, i + 1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factors of %d: ", n);
    findFactors(n, 1);
    printf("\n");
    return 0;
}
