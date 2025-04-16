#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> dijkstraApply(vector<pair<int,int>>adj[],int n,int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //minheap....
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto it:adj[u]){
            int v=it.first;  //it is graph pair {v,w}...
            int w=it.second;
            if(dist[u] + w < dist[v]){
                dist[v]=dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
int main(){
    int n,e;
    cout<<"Enter no. of vertices & edges:";
    cin>>n>>e;
    vector<pair<int,int>>adj[n];
    int u,v,w;
    cout<<"Enter (u, v, w):"<<endl;
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w}); //directed graph...
    }
    int src;
    cout<<"Enter src:";
    cin>>src;
    vector<int>dist=dijkstraApply(adj,n,src);

    
    for(int i=0;i<dist.size();i++){
        if(dist[i]==INT_MAX){
            cout<<"Distance from "<<src<<" node to "<<i<<" is: INF"<<endl; 
        }
        else{
            cout<<"Distance from "<<src<<" node to "<<i<<" is: "<<dist[i]<<endl; 
        }
    }
    return 0;
}