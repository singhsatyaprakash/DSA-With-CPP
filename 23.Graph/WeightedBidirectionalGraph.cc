#include<iostream>
#include<list>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>>*l;// pair(vertex,weight on edge)
    public:
    Graph(int V){
        this->V=V;
        l=new list<pair<int,int>>[V];
    }
    void addEdge(int u,pair<int,int>v){ //u-->initial  v-->final position
        l[u].push_back(v);
        l[v.first].push_back(make_pair(u,v.second));
    }
    void printGraph(){
        for(int i=0;i<V;i++){
            list<pair<int,int>>neigbours=l[i];
            cout<<i<<":";
            for(pair<int,int> it:neigbours){
                cout<<"("<<it.first<<","<<it.second<<"),";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph graph(5);
    graph.addEdge(0,make_pair(1,5));
    graph.addEdge(1,make_pair(2,6));
    graph.addEdge(1,make_pair(3,2));
    graph.addEdge(2,make_pair(3,8));
    graph.addEdge(3,make_pair(0,1));
    graph.printGraph();
    return 0;

}