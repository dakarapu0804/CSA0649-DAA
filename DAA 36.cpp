#include <stdio.h>

#define V 5 // number of vertices

int graph[V][V] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {0, 1, 1, 1, 0}
};

int isSafe(int path[], int pos) {
    if (graph[path[pos - 1]][path[pos]] == 0) {
        return 0;
    }
    for (int i = 0; i < pos; i++) {
        if (path[i] == path[pos]) {
            return 0;
        }
    }
    return 1;
}

int hamiltonianCircuit(int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(path, pos)) {
            path[pos] = v;
            if (hamiltonianCircuit(path, pos + 1)) {
                return 1;
            }
            path[pos] = -1;
        }
    }
    return 0;
}

int main() {
    int path[V];
    path[0] = 0;
    if (hamiltonianCircuit(path, 1)) {
        printf("Hamiltonian circuit: ");
        for (int i = 0; i < V; i++) {
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]);
    } else {
        printf("No Hamiltonian circuit\n");
    }
    return 0;
}
