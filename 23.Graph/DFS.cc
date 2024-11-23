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
    void print(){
        for(int u=0;u<V;u++){
             list<int> neigbours=l[u];
            cout<<u<<":";
            for(int v: neigbours){
                cout<<v<<" "; 
            }
            cout<<endl;
        }
    }
    void dfsHelper(int u,vector<bool>&vis){
        vis[u]=true;
        cout<<u<<" ";
        //accesing 1st unvistied negibour and keep going
        list<int>neghibour=l[u];
        for(int v:neghibour){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void DFS(){
        vector<bool>vis(V,false);
        dfsHelper(0,vis);
        cout<<endl;
    }
};
int main(){
    Graph graph(5);//undirected graph
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    graph.print();
    cout<<"DFS traversal: ";
    graph.DFS();
    return 0;
}
