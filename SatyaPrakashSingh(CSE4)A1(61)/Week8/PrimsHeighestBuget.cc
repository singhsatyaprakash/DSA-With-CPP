#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> PrimsAlgorithm(vector<vector<pair<int,int>>>&adj,int n,int src){
    vector<vector<int>>mst;//{u,v,w}
    vector<bool>vis(n,false);
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{src,-1}}); //{wt,node,parent}
    int maxcost=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int currWt=it.first;
        int currNode=it.second.first;
        int parNode=it.second.second;   
        if(vis[currNode]) continue;
        vis[currNode] = true;
        if(parNode != -1){
            maxcost+=currWt;
            mst.push_back({parNode, currNode, currWt});
        }
        
        for(auto it: adj[currNode]) {
            int adjNode = it.first;
            int adjNodeWt = it.second;
            if(!vis[adjNode])
                pq.push({adjNodeWt, {adjNode, currNode}});
        }
        
    }
    cout<<"Maximum MST:"<<maxcost<<endl;
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
    int maxcost=0;
    for(auto it:mst){
        maxcost+=it[2];
        cout<<"Connected "<<it[0]<<" node with "<<it[1]<<" node with edges weight: "<<it[2]<<endl;
    }
    cout<<"Maximum cost MST:"<<maxcost<<endl;
    return 0;
}