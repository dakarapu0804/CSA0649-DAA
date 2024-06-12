#include <stdio.h>

void sumOfSubsets(int arr[], int n, int sum, int currSum, int index, int subset[]) {
    if (currSum == sum) {
        printf("Subset: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }
    if (currSum > sum) {
        return;
    }
    for (int i = 0; i < n; i++) {
        subset[index] = arr[i];
        sumOfSubsets(arr, n, sum, currSum + arr[i], index + 1, subset);
    }
}

int main() {
    int arr[100], n, sum;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the sum: ");
    scanf("%d", &sum);
    int subset[100];
    sumOfSubsets(arr, n, sum, 0, 0, subset);
    return 0;
}
