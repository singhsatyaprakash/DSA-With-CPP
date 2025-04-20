#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>BellmanFord(vector<vector<int>>edges,int V,int src){
    vector<int>dist(V,INT_MAX);
    //v-1 times edges relaxtaion
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        for(auto it:edges){
            int u=it[0], v=it[1] ,w=it[2];
            if(dist[u]!=INT_MAX && dist[u]+w< dist[v]){
               dist[v]=dist[u]+w; 
            }
        }
    }

    for(auto it:edges){
        int u=it[0], v=it[1] ,w=it[2];
        if(dist[u]!=INT_MAX && dist[u]+w< dist[v]){
           return {-1};
           //negative cycle detected...
        }
    }
    return dist;
    
}
int main(){
    int V,E;
    cout<<"Enter no. of vertex & edges:";
    cin>>V>>E;
    vector<vector<int>>edges;
    int u,v,w;
    cout<<"Enter Edges(u, v, w):"<<endl;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    cout<<"Enter src:";
    int src;
    cin>>src;
    vector<int>dist=BellmanFord(edges,V,src);
    for(int i=0;i<dist.size();i++){
        if(dist[i]!=INT_MAX){
            cout<<"From "<<src<<" to "<<i<<" distance is: "<<dist[i]<<endl;
        }
        else{
            cout<<"From "<<src<<" to "<<i<<" distance is: "<<"INF"<<endl;
        }
    }
    return 0;
}