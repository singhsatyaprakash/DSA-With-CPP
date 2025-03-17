#include <iostream>
#include <vector>

using namespace std;

void DFSUtil(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    cout << node << " ";
    visited[node] = true;

    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFSUtil(graph, visited, i);
        }
    }
}

void DFS(vector<vector<int>>& graph, int start) {
    int v = graph.size();
    vector<bool> visited(v, false);

    cout << "DFS Traversal: ";
    DFSUtil(graph, visited, start);
    cout << endl;
}

int main() {
    int v, e, src, dst, start;
    cout << "Enter number of vertices: ";
    cin >> v;

    // Initialize adjacency matrix with 0
    vector<vector<int>> graph(v, vector<int>(v, 0));

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (src dest):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> src >> dst;
        graph[src][dst] = 1;
        graph[dst][src] = 1; // Undirected graph
    }

    cout << "Enter starting node for DFS: ";
    cin >> start;

    DFS(graph, start);

    return 0;
}
