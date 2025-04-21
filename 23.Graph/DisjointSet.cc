#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    public:
    int n;
    vector<int>rank;
    vector<int>par;
    DisjointSet(int n){
        this->n=n;
        for(int i=0;i<n;i++){
            par.push_back(i); //self parent or leader...
            rank.push_back(0); //initially have rank 0...
        }
    }
    int findPar(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=findPar(par[x]);
    }

    void UnionByRank(int a,int b){
        int parA=findPar(a);
        int parB=findPar(b);
        if(rank[parA]==rank[parB]){
            par[parB]=parA; // a become parent of b;
            rank[parA]++; //rank of a will increase...
        }
        else if(rank[parA]>rank[parB]){
            par[parB]=parA; //rank will same already high rank
        }
        else{
            par[parA]=parB;
        }
    }
};
int main(){
    DisjointSet ds(6);
    ds.UnionByRank(0,2);
    ds.UnionByRank(1,3);
    ds.UnionByRank(2,5);
    ds.UnionByRank(0,3);
    cout<<(ds.findPar(2)==ds.findPar(3))<<endl; //true
    cout<<(ds.findPar(0)==ds.findPar(4))<<endl; //false

    return 0;
}