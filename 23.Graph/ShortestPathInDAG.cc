#include<iostream>
#include<vector>
#include<climits>
#include<stack>
using namespace std;
void topoSort(int src,vector<pair<int,int>>adj[],vector<bool>&vis,stack<int>&st){
    vis[src]=true;
    for(auto it:adj[src]){
        int v=it.first;
        if(!vis[v]){
            topoSort(v,adj,vis,st);
        }
    }
    st.push(src);
}
void ShortestPath(vector<pair<int,int>>adj[],int n){
    cout<<"Enter src:";
    int src;
    cin>>src;
    vector<bool>vis(n,false);
    stack<int>st;
    topoSort(src,adj,vis,st);
    // for(int i=0;i<n;i++){
    //     if(!vis[i]){
    //         topoSort(i,adj,vis,st);
    //     }
    // }
    vector<int>distance(n,INT_MAX);
    distance[src]=0;
    while(!st.empty()){//preform edges relaxation...
        int u=st.top();
        st.pop();
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(distance[u] + w < distance[v]){
                distance[v]=distance[u]+w;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(distance[i]==INT_MAX){
            cout<<"Distance from "<<src<<" to "<<i<<" is: "<<"INF";
        }
        else{
            cout<<"Distance from "<<src<<" to "<<i<<" is: "<<distance[i];
        }
        cout<<endl;
    }
}
int main(){
    int n,e;
    cout<<"Enter no. of vertices and edges:";
    cin>>n>>e;
    vector<pair<int,int>>adj[n];
    int u,v,w;
    cout<<"Enter (u,v,w):";
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    ShortestPath(adj,n);
}