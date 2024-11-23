#include<iostream>
#include<vector>
#include<list>
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
    bool hasPathHelper(int src,int dest,vector<bool>&vis){
        if(src==dest){
            return true;
        }
        vis[src]=true;
        list<int>neghibour=l[src];
        for(int v: neghibour){
            if(!vis[v]){
                if(hasPathHelper(v,dest,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPath(int src,int dest){
        vector<bool>vis(V,false);//not to get stuck in loop
        return hasPathHelper(src,dest,vis);
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
    cout<<graph.hasPath(0,6);//(src,dest)
    return 0;
}
