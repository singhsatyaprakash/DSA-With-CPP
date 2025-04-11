#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isBipartite(vector<int>adj[],int V,int src){
    queue<int>q;
    vector<bool>vis(V,false);
    vector<int>color(V,-1);
    q.push(src);
    vis[src]=true;
    color[src]=0;//0-yellow 1-green
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=true;
                color[it]=!color[node];
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
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
    if(isBipartite(adj,V,0)){
        cout<<"Graph is Bipartite."<<endl;
    }
    else{
        cout<<"Graph is not Bipartite."<<endl;
    }
    return 0;
}