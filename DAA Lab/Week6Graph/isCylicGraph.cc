#include<iostream>
#include<vector>
using namespace std;
bool isCycle(vector<int>adj[],vector<int>&vis,vector<int>&recPath,int s){
    vis[s]=1;
    recPath[s]=1;
    for(auto it:adj[s]){
        if(!vis[it]){
            vis[it]=true;
            if(isCycle(adj,vis,recPath,it)){
                return true;
            }
        }
        else if(recPath[it]){
            return true;
        }
    }
    recPath[s]=0;
    return false;
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
    }
    cout<<"Graph:"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<":";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    int flag=0;
    vector<int>vis(V,0);
    vector<int>recPath(V,0);
    for(int i=0;i<=V;i++){
        if(!vis[0]){
            if(isCycle(adj,vis,recPath,i)){
                flag=1;
                cout<<"Cycle Detected"<<endl;
                break;
            }
        }
    }
    if(flag==0){
        cout<<"No Cycle detected."<<endl;
    }
    return 0;
}