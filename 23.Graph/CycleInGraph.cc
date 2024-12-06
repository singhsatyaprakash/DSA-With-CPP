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
    void AddEdge(int u,int v){\
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
    void BFS(){
        queue<int>q;
        vector<bool>vis(V,false);
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            list<int>neghibour=l[curr];
            for(int v:neghibour){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    bool dfsCycleHelper(vector<bool>&vis,int par,int src){
        vis[src]=true;
        list<int>neigbours=l[src];
        for(int v:neigbours){
            if(!vis[v]){
                if(dfsCycleHelper(vis,src,v)){
                    return true;
                }
            }
            else{
                if(v!=par){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycleExist(){
        vector<bool>vis(V,false);
        return dfsCycleHelper(vis,-1,0);
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
    cout<<graph.isCycleExist();
    return 0;
}