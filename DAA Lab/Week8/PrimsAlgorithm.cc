#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> PrimsAlgorithm(vector<vector<pair<int,int>>>&adj,int n,int src){
    vector<vector<int>>mst;//{u,v,w}
    vector<bool>vis(n,false);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
    pq.push({0,{src,-1}}); //{wt,node,parent}
    int mincost=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int currWt=it.first;
        int currNode=it.second.first;
        int parNode=it.second.second;
        if(vis[currNode]) continue;
        vis[currNode] = true;
        if(parNode != -1){
            mincost+=currWt;
            mst.push_back({parNode, currNode, currWt});
        }
        
        for(auto it: adj[currNode]) {
            int adjNode = it.first;
            int adjNodeWt = it.second;
            if(!vis[adjNode])
                pq.push({adjNodeWt, {adjNode, currNode}});
        }
        
    }
    cout<<"Mincost MST:"<<mincost<<endl;
    return mst;
}
int main(){
    int n,e;
    cout<<"Enter no.of vertices & edges:";
    cin>>n>>e;
    vector<vector<pair<int,int>>>adj(n);
    int u,v,w;
    cout<<"Enter u,v,w:"<<endl;
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cout<<"Enter src:";
    int src;
    cin>>src;
    vector<vector<int>>mst=PrimsAlgorithm(adj,n,src);
    int mincost=0;
    for(auto it:mst){
        mincost+=it[2];
        cout<<"Connected "<<it[0]<<" node with "<<it[1]<<" node with edges weight: "<<it[2]<<endl;
    }
    cout<<"Mincost MST:"<<mincost<<endl;
    return 0;
}