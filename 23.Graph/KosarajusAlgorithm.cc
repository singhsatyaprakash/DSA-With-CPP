//Strongly connected components
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfsComp(int src,vector<int>adj[],int n,vector<bool>&vis){
    vis[src]=true;
    cout<<src<<" ";//Strongely connectecd componets in one row...
    for(auto it:adj[src]){
        if(!vis[it]){
            
            dfsComp(it,adj,n,vis);
        }
    }
}
void dfsStore(int src,vector<int>adj[],int n,vector<bool>&vis,stack<int>&st){
    vis[src]=true;
    for(auto it:adj[src]){
        if(!vis[it]){
            dfsStore(it,adj,n,vis,st);
        }
    }
    st.push(src);
}
void strongleyConnectedComponents(vector<int>adj[],int n){

    //sort all edegs acoording to finishing time...//apply dfs
    stack<int>st;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfsStore(i,adj,n,vis,st);
        }
    }
    //reverse all the edges direction...
    vector<int>rgraph[n];
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            rgraph[it].push_back(i);
        }
    }
    cout<<"Strongely connected components are:"<<endl;
    vector<bool>rvis(n,false);
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!rvis[top]){
            dfsComp(top,rgraph,n,rvis);
            cout<<endl;
        }

    }



}
int main(){
    cout<<"Enter no.of vertices and edges:";
    int n,e;
    cin>>n>>e;
    cout<<"Enter edges(u,v):"<<endl;
    vector<int>graph[n];
    int u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        graph[u].push_back(v);
    }
    strongleyConnectedComponents(graph,n);
    return 0;
    
}