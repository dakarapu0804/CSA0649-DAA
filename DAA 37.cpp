#include <stdio.h>

#define MAX_CONTAINERS 10
#define MAX_ITEMS 10

int containerLoader(int containers[], int items[], int n, int m) {
    int i, j, maxLoad = 0, load = 0;
    for (i = 0; i < n; i++) {
        load = 0;
        for (j = 0; j < m; j++) {
            if (items[j] <= containers[i]) {
                load += items[j];
                containers[i] -= items[j];
            }
        }
        if (load > maxLoad) {
            maxLoad = load;
        }
    }
    return maxLoad;
}

int main() {
    int containers[MAX_CONTAINERS], items[MAX_ITEMS], n, m;
    printf("Enter the number of containers: ");
    scanf("%d", &n);
    printf("Enter the capacities of the containers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &containers[i]);
    }
    printf("Enter the number of items: ");
    scanf("%d", &m);
    printf("Enter the weights of the items: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &items[i]);
    }
    int maxLoad = containerLoader(containers, items, n, m);
    printf("Maximum load: %d\n", maxLoad);
    return 0;
}
