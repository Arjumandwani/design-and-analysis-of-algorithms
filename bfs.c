
#include<stdio.h>

int total;
int graph[10][10];
int visited[10]; // declared globally

void BFS(int);

int main() {
    int i, j;
    
    printf("Enter the total number of vertices in a graph: ");
    scanf("%d", &total);
    
    printf("\nEnter the values for the adjacency matrix:\n");
    for(i = 0; i < total; i++) {
        for(j = 0; j < total; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    for(i = 0; i < total; i++) {
        visited[i] = 0;
    }
    
    BFS(0); // corrected the function call
    
    return 0;
}

void BFS(int vertex) {
    int j;
    printf("%d\t", vertex);
    visited[vertex] = 1;
    for(j = 0; j < total; j++) {
        if(!visited[j] && graph[vertex][j] == 1) {
            BFS(j);
        }
    }
}
