#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>>&graph,int V){
    vector<bool>vis(V+1,false);
    queue<int>q;
    int s;//staring node
    cout<<"Enter starting node:";
    cin>>s;
    q.push(s);
    vis[s]=true;
    cout<<"BFS Traversal:"<<endl;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int i=1;i<=V;i++){
            if(graph[curr][i] && !vis[i]){
                q.push(i);
                vis[i]=true;
            }
        }
    }
}
void dfs(vector<vector<int>>&graph,int V,int src,vector<bool>&vis){
    vis[src]=true;
    cout<<src<<" ";
    for(int i=1;i<=V;i++){
        if(graph[src][i] && !vis[i]){
            dfs(graph,V,i,vis);
            vis[i]=true;
        }
    }
}

bool checkCycledfs(vector<vector<int>>&graph,int V,int src,int parent,vector<bool>vis){
    vis[src]=true;
    for(int i=1;i<=V;i++){
        if(graph[src][i] && !vis[i]){
            if(checkCycledfs(graph,V,i,src,vis)){
                return true;
            }
        }
        else if(graph[src][i] && i!=parent){
            return true;
        }
    }
    return false;
}
bool checkCycle(vector<vector<int>>&graph,int V,vector<bool>&vis){
    return checkCycledfs(graph,V,1,-1,vis);
}
int main(){
    int V,E;
    cout<<"Enter number of vertices:";
    cin>>V;
    cout<<"Enter number of edges:";
    cin>>E;
    vector<vector<int>>graph(V+1,vector<int>(V+1,0));
    cout<<"Enter edges:(src,dst):";
    int u,v;
    for(int i=0;i<E;i++){
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;  
    }
    cout<<"Graph:"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    bfs(graph,V);
    int src;
    cout<<"Enter starting node:";
    cin>>src;
    cout<<"\nDFS Traversal:"<<endl;
    vector<bool>vis(V+1,false);
    dfs(graph,V,src,vis);

    vis.assign(V+1,false);
    if(checkCycle(graph,V,vis)){
        cout<<"\nGraph has cycle"<<endl;
    }
    else{
        cout<<"\nGraph has no cycle"<<endl;
    }
    return 0;
}