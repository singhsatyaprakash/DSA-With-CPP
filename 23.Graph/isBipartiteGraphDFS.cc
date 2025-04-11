#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V; //how many vertex graph has..
    list<int>*l;
    bool isdirected;
    public:
    Graph(int V,bool isdirected=false){
        this->V=V;
        l=new list<int>[V];
        this->isdirected=isdirected;
    }
    void AddEdge(int u,int v){
        l[u].push_back(v);
        if(!isdirected){ //if not direct..
            l[v].push_back(u);
        }
    }
    void PrintGraph(){
        for(int u=0;u<V;u++){
             list<int> neigbours=l[u];
            cout<<u<<":";
            for(int v: neigbours){
                cout<<v<<" "; 
            }
            cout<<endl;
        }
    }
    
    

};
int main(){
    //Graph graph(5,true);//directed
    Graph graph(5); //undirected
    graph.AddEdge(0,1); //(src,dest)
    graph.AddEdge(1,2);
    graph.AddEdge(2,0);
    graph.AddEdge(0,3);
    graph.AddEdge(3,4);
    graph.PrintGraph();
    return 0;
}