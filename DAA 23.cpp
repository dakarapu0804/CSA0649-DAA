#include <stdio.h>

int min(int a, int b) {
    return (a < b)? a : b;
}

int binomialCoeff(int n, int k) {
    int C[n + 1][k + 1];
    int i, j;

    // Calculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            // Base cases
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

int main() {
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    if(k > n) {
        printf("k cannot be greater than n\n");
        return 1;
    }

    printf("Binomial Coefficient (%d choose %d) is: %d\n", n, k, binomialCoeff(n, k));
    return 0;
}
