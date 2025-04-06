#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices

// Function to check if current color assignment is valid
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Recursive utility to try coloring the graph
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;  // All vertices are colored

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0;  // Backtrack
        }
    }

    return false;  // No color can be assigned
}

// Main function to solve the m-coloring problem
bool graphColoring(int graph[V][V], int m) {
    int color[V] = {0};

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist.\n");
        return false;
    }

    printf("Solution exists with %d colors:\n", m);
    for (int i = 0; i < V; i++)
        printf("Vertex %d -> Color %d\n", i, color[i]);

    return true;
}

// Example usage
int main() {
    // Example graph (adjacency matrix)
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3;  // Number of colors
    graphColoring(graph, m);

    return 0;
}
