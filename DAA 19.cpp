#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

typedef struct {
    int value;
    int weight;
} Item;

void knapsack(Item items[], int n, int W) {
    int i, w;
    int totalValue = 0;

    // Sort items by value-to-weight ratio in descending order
    for (i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].value / items[i].weight < items[j].value / items[j].weight) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Greedy selection of items
    for (i = 0; i < n; i++) {
        if (w + items[i].weight <= W) {
            w += items[i].weight;
            totalValue += items[i].value;
            printf("Selected item %d with value %d and weight %d\n", i, items[i].value, items[i].weight);
        }
    }

    printf("Total value: %d\n", totalValue);
}

int main() {
    int n, W;
    Item items[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    knapsack(items, n, W);

    return 0;
}
