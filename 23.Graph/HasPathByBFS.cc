#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V; //Count of vertices
    list<int> *l; //store list of integer int* arr
    public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V]; //arr= new int[n] we store a list in each indices...
    }
    void addEdge(int u,int v){ //edge from u to v
        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool hasPath(int src,int dest){
        queue<int>q;
        vector<bool>vis(V,false);
        vis[src]=true;
        q.push(src);
        while(!q.empty()){
            int curr=q.front();
            if(curr==dest){
                return true;
            }
            q.pop();
            list<int>neghibour=l[curr];
            for(int v:neghibour){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph graph(7);//undirected graph
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    cout<<graph.hasPath(0,6);//(src,dest)  //1
    cout<<"\n"<<graph.hasPath(6,7);//(src,dest)  //0
    return 0;
}
