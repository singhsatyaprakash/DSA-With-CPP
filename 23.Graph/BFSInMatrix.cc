#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& graph, int start) {
    int v = graph.size();
    vector<bool> visited(v, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < v; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
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
        graph[dst][src] = 1; // Since it's an undirected graph
    }

    cout << "Enter starting node for BFS: ";
    cin >> start;

    BFS(graph, start);

    return 0;
}
