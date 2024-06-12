#include <stdio.h>
#include <math.h>

int countDigits(int n) {
    if (n == 0)
        return 0;
    else
        return 1 + countDigits(n / 10);
}

int power(int n, int r) {
    if (r == 0)
        return 1;
    else
        return n * power(n, r - 1);
}

int isArmstrong(int n, int temp, int digits) {
    if (n == 0)
        return temp;
    else {
        int rem = n % 10;
        temp = temp + power(rem, digits);
        return isArmstrong(n / 10, temp, digits);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int digits = countDigits(num);
    int result = isArmstrong(num, 0, digits);
    if (result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
    return 0;
}
