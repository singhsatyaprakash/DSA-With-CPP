/* Given a directed graph with two vertices ( source and destination). Design an algorithm and
 implement it using a program to find the weight of the shortest path from source to destination
 with exactly k edges on the path.*/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int ShortestWithK(vector<pair<int,int>> adj[], int src, int dst, int k, int V) {

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {src, 0}}); //wt,src,steps

    while (!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int steps = pq.top().second.second;
        pq.pop();

        if (node == dst && steps == k) {
            return wt;
        }
        if (steps > k) continue;

        for (auto it : adj[node]) {
            pq.push({wt + it.second, {it.first, steps + 1}});
        }
    }
    return -1; 
}

int main() {
    int V, E;
    cout << "Enter no. vertices & edges:";
    cin >> V >> E;
    vector<pair<int,int>> adj[V];
    int u, v,w;
    cout << "Enter u & v & w:" << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v>>w;
        adj[u].push_back({v,w});
    }
    int src, dst, k;
    cout << "Enter src & dst:";
    cin >> src >> dst;
    cout << "Enter k steps:";
    cin >> k;
    int weight = ShortestWithK(adj, src, dst, k, V);
    if (weight == -1)
        cout << "No path with exactly " << k << " edges." << endl;
    else
        cout << "Shortest Weight is: " << weight << endl;
    return 0;
}