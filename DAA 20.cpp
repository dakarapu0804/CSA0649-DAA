#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent;
    int rank;
} UnionFind;

UnionFind uf[MAX_VERTICES];

void makeSet(int v) {
    uf[v].parent = v;
    uf[v].rank = 0;
}

int find(int v) {
    if (uf[v].parent != v) {
        uf[v].parent = find(uf[v].parent);
    }
    return uf[v].parent;
}

void unionSets(int u, int v) {
    int root1 = find(u);
    int root2 = find(v);

    if (root1 != root2) {
        if (uf[root1].rank > uf[root2].rank) {
            uf[root2].parent = root1;
        } else {
            uf[root1].parent = root2;
            if (uf[root1].rank == uf[root2].rank) {
                uf[root2].rank++;
            }
        }
    }
}

void kruskal(Edge edges[], int n, int V) {
    int i, j;
    Edge mst[MAX_EDGES];

    // Sort edges by weight in non-decreasing order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    // Initialize Union-Find data structure
    for (i = 0; i < V; i++) {
        makeSet(i);
    }

    // Greedy selection of edges
    int mstIndex = 0;
    for (i = 0; i < n; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            mst[mstIndex++] = edges[i];
            unionSets(u, v);
        }
    }

    // Print MST
    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < mstIndex; i++) {
        printf("%d -- %d == %d\n", mst[i].u, mst[i].v, mst[i].weight);
    }
}

int main() {
    int V, E;
    Edge edges[MAX_EDGES];

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, E, V);

    return 0;
}
