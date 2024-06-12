#include <stdio.h>

#define V 4 // number of vertices

int isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

int graphColoring(int graph[V][V], int color[], int v) {
    if (v == V) {
        return 1;
    }
    for (int c = 1; c <= V; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;
            if (graphColoring(graph, color, v + 1)) {
                return 1;
            }
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int color[V] = {0};
    if (graphColoring(graph, color, 0)) {
        printf("Coloring: ");
        for (int i = 0; i < V; i++) {
            printf("%d ", color[i]);
        }
        printf("\n");
    } else {
        printf("No coloring possible\n");
    }
    return 0;
}
