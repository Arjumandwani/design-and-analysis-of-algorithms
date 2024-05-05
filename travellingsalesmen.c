#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the shortest Hamiltonian cycle using dynamic programming
int tsp(int graph[][V], int mask, int pos, int dp[][V]) {
    // If all cities have been visited, return the cost of returning to the original city
    if (mask == (1 << V) - 1)
        return graph[pos][0];

    // If the subproblem is already solved, return the result from the dp table
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    // Initialize result to maximum integer value
    int res = INT_MAX;

    // Try all cities as the next city from the current city
    int i;
    for ( i = 0; i < V; i++) {
        // If the city is not visited and not the same as the current city
        if (!(mask & (1 << i)) && graph[pos][i]) {
            // Update the result with the cost of the path including the current city
            int tmp = graph[pos][i] + tsp(graph, mask | (1 << i), i, dp);
            res = min(res, tmp);
        }
    }

    // Save the result in the dp table and return
    return dp[mask][pos] = res;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Initialize dp table with -1
    int dp[1 << V][V];
    int i,j;
    for ( i = 0; i < (1 << V); i++)
        for (j = 0; j < V; j++)
            dp[i][j] = -1;

    // Starting from the first city (0) and no cities visited yet
    printf("Minimum cost of the TSP: %d\n", tsp(graph, 1, 0, dp));

    return 0;
}
