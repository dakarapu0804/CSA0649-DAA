#include <stdio.h>

int reverseNumber(int num, int rev) {
    if (num == 0)
        return rev;
    else {
        rev = rev * 10 + num % 10;
        return reverseNumber(num / 10, rev);
    }
}

int main() {
    int num, rev = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    rev = reverseNumber(num, rev);
    printf("Reverse of %d is: %d\n", num, rev);
    return 0;
}
