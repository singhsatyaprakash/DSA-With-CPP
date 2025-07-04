#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int>> floydWarshall(int V, vector<vector<int>>& edges) {
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    for(int i=0; i<V; i++) dist[i][i] = 0;
    for(auto it : edges) {
        int u = it[0], v = it[1], w = it[2];
        dist[u][v] = w;
    }
    for(int k=0; k<V; k++) {
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    // Negative cycle detection (after all updates)
    bool negativeCycle = false;
    for(int i=0; i<V; i++) {
        if(dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE DETECTED..." << endl;
            negativeCycle = true;
            break;
        }
    }
    return dist;
}

int main() {
    int V, E;
    cout << "Enter no. of vertex & edges:";
    cin >> V >> E;
    vector<vector<int>> edges;
    int u, v, w;
    cout << "Enter Edges(u, v, w):" << endl;
    for(int i=0; i<E; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        // edges.push_back({v, u, w}); // Only if undirected
    }
    vector<vector<int>> dist = floydWarshall(V, edges);

    for(int i=0; i<dist.size(); i++) {
        for(int j=0; j<dist.size(); j++) {
            if(dist[i][j] != INT_MAX) {
                cout << "From " << i << " to " << j << " distance is: " << dist[i][j] << endl;
            } else {
                cout << "From " << i << " to " << j << " distance is: Not Reachable" << endl;
            }
        }
    }
    return 0;
}