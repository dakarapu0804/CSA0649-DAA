#include <stdio.h>

int binary_search(int arr[], int target, int low, int high) {
    if (low > high) {
        return -1; 
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        return mid; 
    } else if (arr[mid] < target) {
        return binary_search(arr, target, mid + 1, high);
    } else {
        return binary_search(arr, target, low, mid - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binary_search(arr, target, 0, n - 1);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
