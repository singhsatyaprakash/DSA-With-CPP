#include<iostream>
#include<vector>
using namespace std;
bool dfs(vector<int>adj[],int V,vector<bool>&vis,int src, int dst){
    if(src==dst){
        return true;
    }
    vis[src]=true;
    for(auto it:adj[src]){
        if(!vis[it]){
            if(dfs(adj,V,vis,it,dst)){
                return true;
            }
        }
    }
    return false;
}
bool haspathExists(vector<int>adj[],int V,int src, int dst){
    vector<bool>vis(V,false);
    return dfs(adj,V,vis,src,dst);
}
int main(){
    int V,E;
    cout<<"Enter number of vertices and edges:";
    cin>>V>>E;
    vector<int>adj[V];//0-based
    cout<<"Enter (u,v):"<<endl;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    cout<<"Graph:"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<":";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    int src,dst;
    cout<<"Enter src and dst node:";
    cin>>src>>dst;
    if(haspathExists(adj,V,src,dst)){
        cout<<"Yes Path exists."<<endl;
    }
    else{
        cout<<"Path does not exist."<<endl;
    }
    return 0;
}