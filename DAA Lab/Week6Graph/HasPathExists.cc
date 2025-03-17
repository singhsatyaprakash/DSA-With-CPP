#include<iostream>
#include<vector>
using namespace std;
bool haspathExists(vector<int>adj[],int V){
    vector<
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
    if(haspathExists(adj,V)){
        cout<<"Path exists."<<endl;
    }
    else{
        cout<<"Path does not exist."<<endl;
    }
    return 0;
}