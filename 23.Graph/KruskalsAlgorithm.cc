#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Edge{
    public:
        int u,v,w;
        Edge(int u,int v,int w): u(u),v(v),w(w){}
};
class Graph{
    public:
    vector<int>par;
    vector<int>rank;
    vector<Edge>edges;
    int V;
    Graph(int V){
        this->V=V;
        for(int i=0;i<V;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]);
    }
    void unionByRank(int u,int v){
        int parU=find(u);
        int parV=find(v);
        if(rank[parU]==rank[parV]){
            par[parV]=parU;
            rank[parU]++;
        }
        else if(rank[parU]>rank[parV]){
            par[parV]=parU;
        }
        else{
            par[parU]=parV;
        }
    }

    void addEdge(int u,int v,int w){
        edges.push_back(Edge(u,v,w));//bidirectional
        edges.push_back(Edge(v,u,w));
    }
    void Kruskal(){
        sort(edges.begin(),edges.end(),[](Edge &a,Edge &b){
            return a.w<b.w;
        });

        vector<vector<int>>mst;//{{u,v,wt}}
        int mincost=0;
        int count=0;
        for(int i=0;i<edges.size() && count<V-1;i++){
            auto it=edges[i];
            int parU=find(it.u);
            int parV=find(it.v);
            if(parU!=parV){
                unionByRank(parU,parV);
                mst.push_back({it.u,it.v,it.w});
                mincost+=it.w;
                count++;
            }
        }
        cout<<"Minimum cost of MST:"<<mincost<<endl;
        for(int i=0;i<mst.size();i++){
                int u=mst[i][0];
                int v=mst[i][1];
                int w=mst[i][2];
                cout<<"connect node "<<u<<" with node "<<v<< " with edge weight: "<<w<<endl;
        }
    }
};
int main(){
    Graph graph(5);
    graph.addEdge(0,1,2);
    graph.addEdge(0,2,1);
    graph.addEdge(2,1,1);
    graph.addEdge(2,4,2);
    graph.addEdge(2,3,2);
    graph.addEdge(4,3,1);
    graph.Kruskal();
    return 0;
}