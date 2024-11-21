#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dst;
    struct node* next;
} graph_type;

// Function to add an edge to the graph
void addEdge(graph_type* graph[], int src, int dst) {
    // Create a new node for the destination
    graph_type* newNode = (graph_type*)malloc(sizeof(graph_type));
    newNode->dst = dst;
    newNode->next = graph[src]; //graph is head address
    graph[src] = newNode;
}

// Function to print the adjacency list of the graph
void printGraph(graph_type* graph[],int n){
    for (int i = 0; i < n; i++) {
        printf("Node %d:", i);
        graph_type* temp = graph[i];
        while (temp) {
            printf(" -> %d", temp->dst);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    // Initialize the graph
    graph_type* graph[n];
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }
    int src, dst;
    int choice;
    // Interactive loop for adding edges
    do {
        printf("Enter an edge(src,dst):");
        scanf("%d%d",&src,&dst);
        addEdge(graph,src,dst);
        printGraph(graph,n);
        printf("Press[0] to exit:");
        scanf("%d",&choice);
    }while(choice!=0);

    // Print the adjacency list
    printf("\nAdjacency List Representation of the Graph:\n");
    printGraph(graph,n);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        graph_type* temp = graph[i];
        while (temp) {
            graph_type* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }

    return 0;
}
