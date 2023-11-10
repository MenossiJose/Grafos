#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_VERTICES 50
 
// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {
 
    // No. of vertices
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;
 
// Constructor
Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;
    int i;
    int j;
 
    for ( i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }
 
    return g;
}
 
// Destructor
void Graph_destroy(Graph* g) { free(g); }
 
// Function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w)
{
    // Add w to v’s list.
    g->adj[v][w] = true;
}
 
// Prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s)
{
    // Mark all the vertices as not visited
    bool visited[MAX_VERTICES];
    int i;
    for ( i = 0; i < g->V; i++) {
        visited[i] = false;
    }
 
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue[rear++] = s;
 
    while (front != rear) {
 
        // Dequeue a vertex from queue and print it
        s = queue[front++];
        printf("%d ", s);
 
        // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        int adjacent;
        for ( adjacent = 0; adjacent < g->V;
             adjacent++) {
            if (g->adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}
 
// Driver code
int main()
{
    // Create a graph
    Graph* g = Graph_create(15);
    Graph_addEdge(g, 0, 1);
    Graph_addEdge(g, 0, 2);
    Graph_addEdge(g, 1, 3);
    Graph_addEdge(g, 1, 4);
    Graph_addEdge(g, 1, 5);
    Graph_addEdge(g, 3, 6);
    Graph_addEdge(g, 3, 7);
    Graph_addEdge(g, 5, 8);
    Graph_addEdge(g, 5, 9);
    Graph_addEdge(g, 7, 10);
    Graph_addEdge(g, 7, 11);
    Graph_addEdge(g, 7, 12);
    Graph_addEdge(g, 9, 13);
    Graph_addEdge(g, 9, 14);
 
    printf("Following is Breadth First Traversal "
           "(starting from vertex 3) \n");
    Graph_BFS(g, 1);
    Graph_destroy(g);
 
    return 0;
}