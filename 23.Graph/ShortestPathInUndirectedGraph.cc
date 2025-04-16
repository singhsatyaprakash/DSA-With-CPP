#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void findShortest(vector<int>adj[],int n){
    cout<<"Enter source:";
    int src;
    cin>>src;
    queue<int>q;//{node,dist};
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto it:adj[u]){
            if(dist[u]+1<dist[it]){
                dist[it]=dist[u]+1;
                q.push(it);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX){
            cout<<"Distance from "<<src<<" to "<<i<<" is: "<<1e9;
        }
        else{
            cout<<"Distance from "<<src<<" to "<<i<<" is: "<<dist[i];
        }
        cout<<endl;
    }
}
int main(){
    int n,e;
    cout<<"Enter no. of vertices & edges:";
    cin>>n>>e;
    //unit weight graph...
    vector<int>adj[n];
    int u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findShortest(adj,n);
    return 0;
}