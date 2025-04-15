#include<iostream>
#include<vector>
using namespace std;
bool dfsCheck(vector<int>adj[],int src,vector<int>&color,int prevColor){
    color[src]=prevColor;
    for(auto it:adj[src]){
        if(color[it]==-1){ //not visited...
            if(dfsCheck(adj,it,color,!prevColor)==false){
                return false;
            }
        }
        else if(color[it]==prevColor){
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<int>adj[],int V){
    vector<int>color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(dfsCheck(adj,i,color,0)==false){
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
    if(isBipartite(adj,V)){
        cout<<"Graph is Bipartite."<<endl;
    }
    else{
        cout<<"Graph is not Bipartite."<<endl;
    }
    return 0;
}