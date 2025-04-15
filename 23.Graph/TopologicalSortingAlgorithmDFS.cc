#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(vector<int>adj[],vector<bool>&vis,stack<int>&st,int src){
    vis[src]=1;
    for(auto it:adj[src]){
        if(!vis[it]){
            dfs(adj,vis,st,it);
        }
    }
    st.push(src);
}
void topologicalSort(vector<int>adj[],int v){
    vector<bool>vis(v,false);
    stack<int>st;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(adj,vis,st,i);
        }
    }
    cout<<"Topological Sort:";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    int v,e;
    cout<<"Enter no. of vertices & edges:";
    cin>>v>>e;
    vector<int>adj[v];
    cout<<"Enter (u-->v):"<<endl;
    int src,dst;
    for(int i=0;i<e;i++){
        cin>>src>>dst;
        adj[src].push_back(dst);//only directed acyclic graph
    }
    topologicalSort(adj,v);
}