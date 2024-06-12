#include <stdio.h>

void printPattern(int n, int curr) {
    if (curr > n) {
        return;
    }
    for (int i = 1; i <= curr; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printPattern(n, curr + 1);
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printPattern(n, 1);
    return 0;
}
