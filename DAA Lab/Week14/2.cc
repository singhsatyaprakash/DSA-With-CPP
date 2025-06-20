#include <iostream>
#include <vector>
using namespace std;

// Standard DFS
void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for(int u : adj[v]) {
        if(!visited[u])
            dfs(u, adj, visited);
    }
}

// Function to find mother vertex
int findMotherVertex(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int lastV = 0;

    //Find last finished vertex in DFS
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited);
            lastV = i;
        }
    }

    // Reset visited array without using fill
    for(int i = 0; i < V; i++) visited[i] = false;

    dfs(lastV, adj, visited);
    for(bool v : visited) {
        if(!v) return -1; // No mother vertex
    }
    return lastV;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<int>> adj(V);
    cout << "Enter edges (u v) for directed edge u -> v:" << endl;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int mother = findMotherVertex(V, adj);
    if(mother == -1)
        cout << "No mother vertex exists in the graph." << endl;
    else
        cout << "Mother vertex is: " << mother << endl;
    return 0;
}