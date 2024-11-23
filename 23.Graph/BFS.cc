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
    void BFS(){
        queue<int>q;
        vector<bool>vis(V,false);
        //choosing starting point
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int curr=q.front();
            cout<<curr<<" ";
            q.pop();
            //accesing the neghibour of curr node;
            list<int>neigbours=l[curr];
            for(int it:neigbours){
                if(!vis[it]){//not visited
                    q.push(it);//add to queue
                    vis[it]=true;//and marked as visited
                }
            }
        }
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
    cout<<"BFS Travesal:  ";
    graph.BFS();
    return 0;
}
