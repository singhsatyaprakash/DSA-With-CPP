#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<int>adj[],int V){
    int s;
    cout<<"Enter statring index:";
    cin>>s;
    vector<int>vis(V,0);
    queue<int>q;
    q.push(s);
    vis[s]=1;
    cout<<"BFS Traversal:"<<endl;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto i:adj[node]){
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
            }
        }
    }
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
        adj[v].push_back(u);
    }
    cout<<"Graph:"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<":";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    bfs(adj,V);
}