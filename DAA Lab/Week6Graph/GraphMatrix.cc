#include<iostream>
#include<vector>
using namespace std;
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
    return 0;
}