#include<iostream>
#include<vector>
using namespace std;
bool dfs(int src,int dst,vector<bool>&vis,vector<vector<int>>&adj){
    if(src==dst){
        return true;
    }
    vis[src]=true;
    for(auto it:adj[src]){
        if(!vis[it] && it>src){
            if(dfs(it,dst,vis,adj)) return true;
        }
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter no. of node:";
    cin>>n;
    int m;
    cout<<"Enter no. of edges:";
    cin>>m;
    vector<int>a(m);
    vector<int>b(m);
    cout<<"Enter first list of node(Array a):"<<endl;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    cout<<"Enter second list of node(Array b):"<<endl;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    vector<bool>vis(n+1,false);
    int src=1,dst=n;
    if(dfs(src,dst,vis,adj)){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;

}