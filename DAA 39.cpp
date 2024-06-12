#include <stdio.h>
#include <limits.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int cost[MAX_ROWS][MAX_COLS];
int rows, cols;
int minCost = INT_MAX;

void branchAndBound(int row, int col, int currCost, int assigned[]) {
    if (row == rows) {
        if (currCost < minCost) {
            minCost = currCost;
        }
        return;
    }
    for (int j = 0; j < cols; j++) {
        if (!assigned[j]) {
            assigned[j] = 1;
            branchAndBound(row + 1, j, currCost + cost[row][j], assigned);
            assigned[j] = 0;
        }
    }
}

int main() {
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the cost matrix: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    int assigned[cols];
    for (int i = 0; i < cols; i++) {
        assigned[i] = 0;
    }
    branchAndBound(0, 0, 0, assigned);
    printf("Minimum cost: %d\n", minCost);
    return 0;
}
