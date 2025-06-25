#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int dst;
    int wt;
    struct node* next;
} graph_type;

void addEdgeInAscendingOrder(graph_type* source[],int src,int dst,int wt){
    graph_type* newnode=(graph_type*)malloc(sizeof(graph_type));
    newnode->dst=dst;
    newnode->wt=wt;
    newnode->next=NULL;
    if (source[src] == NULL || source[src]->wt >= newnode->wt) {
        newnode->next = source[src];
        source[src] = newnode;
        return;
    }
    // Find the correct position to insert
    graph_type* curr = source[src];
    while (curr->next != NULL && curr->next->wt < newnode->wt) {
        curr = curr->next;
    }

    // Insert the new node at the correct position
    newnode->next = curr->next;
    curr->next = newnode;
}
void dfsTraversal(graph_type* source[],int src,int vis[]){
    vis[src]=1;
    printf("%d ",src);
    graph_type* temp=source[src];
    while(temp!=NULL){
        int i=temp->dst;
        if(!vis[i]){
            dfsTraversal(source,i,vis);
        }
        temp=temp->next;
    }
}
void bfsTraversal(graph_type* source[],int src,int vis[],int n){
    int queue[n];
    int front=0,rear=0;
    vis[src]=1;
    queue[rear++]=src;
    while(front!=rear){
        int curr=queue[front];
        front++;//pop
        printf("%d ",curr);
        graph_type* temp=source[curr];
        while(temp!=NULL){
            if(!vis[temp->dst]){
                queue[rear++]=temp->dst;
                vis[temp->dst]=1;
            }
            temp=temp->next;
        }
    }
}
// Function to print the adjacency list of the graph
void printGraph(graph_type* source[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Node %d:", i);
        graph_type* temp = source[i];
        if (temp == NULL) {
            printf(" No edges");
        }
        while (temp != NULL) {
            printf(" -> (%d, %d)", temp->dst, temp->wt);
            temp = temp->next;
        }
        printf("\n");
    }
}
// Main function
int main() {
    int n;
    printf("Enter the number of Vertex: ");
    scanf("%d", &n);
    // Initialize the graph
    graph_type* source[n];
    for (int i = 0; i < n; i++) {
        source[i] = NULL;
    }
    int src, dst, wt;
    int choice;
    // Interactive loop for adding edges
    do {
        printf("Enter an edge(src,dst,wt):");
        scanf("%d %d %d",&src,&dst,&wt);
        // addEdge(source,src,dst);
        addEdgeInAscendingOrder(source,src,dst,wt);
        printf("Enter Choice:");
        scanf("%d",&choice);
    }while(choice!=0);

    // Print the adjacency list
    printf("\nAdjacency List Representation of the Graph:\n");
    printGraph(source,n);
    int vis[n];
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    printf("\nDFS Traversal:");
    dfsTraversal(source,0,vis);
    // reintialize vistied vector
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    printf("\nBFS Traversal:");
    bfsTraversal(source,0,vis,n);
    return 0;
}
