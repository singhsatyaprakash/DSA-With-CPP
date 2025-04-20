#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> Dijkstra(int src,vector<vector<pair<int,int>>>&adj){
    int V=adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>distance(V,INT_MAX);
    distance[src]=0;
    pq.push({0,src});//distance,src
    while(!pq.empty()){
        auto node=pq.top();
        int d=node.first;
        
        int u=node.second;
        pq.pop();
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(d+w<distance[v]){
                distance[v]=d+w;
                pq.push({w,v});
            }
        }
    }
    return distance;
}
int main(){
    int V,E;
    cout<<"Enter number of vertices and edges:";
    cin>>V>>E;
    vector<vector<pair<int,int>>>adj(V);
    cout<<"Enter edges:(src,dst,wt):"<<endl;
    int u,v,wt;
    for(int i=0;i<E;i++){
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    int source;
    cout<<"Enter source:";
    cin>>source;
    vector<int>distance=Dijkstra(source,adj);
    cout<<"Src node to each node distance:"<<endl;
    for(int i=0;i<V;i++){
        cout<<source<< " --> "<<i<<" with distance:"<<distance[i]<<endl;
    }
    return 0;
}