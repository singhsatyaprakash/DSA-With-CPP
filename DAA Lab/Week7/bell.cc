#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
	vector<int> dist(V, INT_MAX);
	dist[S] = 0;
	for (int i = 0; i < V - 1; i++) {
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}

	// Optional: Uncomment to check for negative cycles
	// for (auto it : edges) {
	// 	int u = it[0];
	// 	int v = it[1];
	// 	int wt = it[2];
	// 	if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
	// 		cout << "Negative weight cycle detected!" << endl;
	// 		break;
	// 	}
	// }

	return dist;
}

int main() {
	int V, E;
	cout << "Enter number of vertices: ";
	cin >> V;
	cout << "Enter number of edges: ";
	cin >> E;

	vector<vector<int>> edges;
	cout << "Enter edges (u, v, wt):" << endl;
	for (int i = 0; i < E; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({u, v, wt});
	}
	int S;
	cout << "Enter source vertex: ";
	cin >> S;

	vector<int> dist = bellmanFord(V, edges, S);
	cout << "Shortest distances from source " << S << ":" << endl;
	for (int i = 0; i < V; i++) {
        cout<<"to vertex ("<<i<<"):";
		if (dist[i] == INT_MAX){
			cout << "Infinity"<<endl;
        }
		else{
			cout << dist[i] << endl;
        }
	}
	cout << endl;

	return 0;
}
