#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool detect(int src,int vis[],vector<int>adj[]){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});//(curr,parent)
    
    while(!q.empty()){
        int curr=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto i:adj[curr]){
            if(!vis[i]){
                vis[i]=1;
                q.push({i,curr});
            }
            else if(parent!=i){ //visite and not parent...
                return true;//cycle detect
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int>adj[V];
    int e=edges.size();
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int vis[V]={0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(i,vis,adj)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int V;
    cout<<"Enter no. of vertices:";
    cin>>V;
    int e;
    cout<<"Enter number of edges:";
    cin>>e;
    vector<vector<int>>edges;
    cout<<"enter edges b/w src & dst node:"<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    if(isCycle(V,edges)){
        cout<<"Yes cycle exist.."<<endl;
    }
    else{
        cout<<"No cycle detected.."<<endl;
    }
    return 0;
}
/*
Enter no. of vertices:4 
Enter number of edges:3
enter edges b/w src & dst node:
0 1
1 2
2 3
No cycle detetec...

Enter no. of vertices:4 
Enter number of edges:4
enter edges b/w src & dst node:
0 1
0 2
1 2
2 3
Yes cycle exist..
*/