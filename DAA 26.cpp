#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve the Traveling Salesman Problem using dynamic programming
int tsp(int graph[][V], int mask, int pos, int dp[][V]) {
    // If all vertices have been visited
    if (mask == (1 << V) - 1) {
        return graph[pos][0]; // Return to starting vertex
    }
    
    // If sub-problem has already been solved
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    // Try all unvisited cities as next destination
    for (int i = 0; i < V; i++) {
        if (!(mask & (1 << i))) { // If city i is not visited
            int newAns = graph[pos][i] + tsp(graph, mask | (1 << i), i, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

// Function to initialize DP array with -1
void init(int dp[][V]) {
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int dp[1 << V][V];
    init(dp);
    
    // Start with the first vertex
    int ans = tsp(graph, 1, 0, dp);

    printf("Minimum cost for TSP is: %d\n", ans);
    
    return 0;
}

