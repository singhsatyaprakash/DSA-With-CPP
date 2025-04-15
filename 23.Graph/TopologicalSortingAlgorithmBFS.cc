//Khan's Algorithm...

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>getIndegree(vector<int>adj[],int n){
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    return indegree;
}
vector<int>toposortBfs(vector<int>adj[],int n){
    vector<int>indeg=getIndegree(adj,n);
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    vector<int>topo;
    while(!q.empty()){
        int curr=q.front();
        topo.push_back(curr);
        q.pop();
        for(auto it:adj[curr]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
}
int main(){
    int n,e;
    cout<<"Enter vertex and edges:";
    cin>>n>>e;
    vector<int>adj[n];
    cout<<"Enter (u,v):"<<endl;
    int u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        adj[u].push_back(v);//directed graph
    }
    vector<int>topo=toposortBfs(adj,n);
    cout<<"TopologicalSort:";
    for(int i=0;i<topo.size();i++){
        cout<<topo[i]<<" ";
    }
    return 0;
}