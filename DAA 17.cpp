#include <stdio.h>

typedef struct {
    int max;
    int min;
}MinMax;

MinMax findMinMax(int arr[], int low, int high) {
    MinMax mm;
    int mid;

    if (low == high) {
        mm.max = arr[low];
        mm.min = arr[low];
        return mm;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            mm.max = arr[low];
            mm.min = arr[high];
        } else {
            mm.max = arr[high];
            mm.min = arr[low];
        }
        return mm;
    }

    mid = (low + high) / 2;

    MinMax mm1 = findMinMax(arr, low, mid);
    MinMax mm2 = findMinMax(arr, mid + 1, high);

    mm.max = (mm1.max > mm2.max)? mm1.max : mm2.max;
    mm.min = (mm1.min < mm2.min)? mm1.min : mm2.min;

    return mm;
}

int main() {
    int arr[] = {3, 2, 7, 1, 5, 9, 8, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax mm = findMinMax(arr, 0, n - 1);

    printf("Maximum element is %d\n", mm.max);
    printf("Minimum element is %d\n", mm.min);

    return 0;
}
