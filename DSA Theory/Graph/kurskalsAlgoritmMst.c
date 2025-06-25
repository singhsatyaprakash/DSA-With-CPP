#include<stdio.h>
#include<stdlib.h>
typedef struct edges{
    int u,v,wt;
}edge_type;
int find(int x,int par[]){
    if(par[x]==x){
        return x;
    }
    return par[x]=find(par[x],par);
}
void unionByRank(int a,int b,int rank[],int par[]){
    int parA=find(a,par);
    int parB=find(b,par);
    if(rank[parA]==rank[parB]){
        par[parB]=parA;
        rank[parA]++;
    }
    else if(rank[parA]<rank[parB]){
        par[parA]=parB;
    }
    else{
        par[parB]=parA;
    }
}
void getMSTByKursakal(edge_type edges[],int e,int n){
    int par[n];
    int rank[n];
    for(int i=0;i<n;i++){
        par[i]=i;
        rank[i]=0;
    }
    //sort the edges on the basis of weight;
    for(int i=0;i<e-1;i++){
        for(int j=0;j<e-i-1;j++){
            if(edges[j].wt > edges[j+1].wt){
                edge_type temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
        }
    }
    int mincost=0,count=0;
    for(int i=0;i<e && count<n-1;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int parU=find(u,par);
        int parV=find(v,par);
        if(parU!=parV){//no cylce
            count++;
            unionByRank(u,v,rank,par);
            mincost+=edges[i].wt;
        }
    }
    printf("Mimimum Cost:%d\n",mincost);
}
int main(){
    int n;
    printf("Enter number of vertex:");
    scanf("%d",&n);
    int src,dst,wt;
    edge_type edges[n];//to store edges with weight at each idx...
    int e=0;
    int choice;
    do{
        printf("Enter (src,dst,wt):");
        scanf("%d%d%d",&src,&dst,&wt);
        edge_type temp;
        temp.u=src;
        temp.v=dst;
        temp.wt=wt;
        edges[e++]=temp;
        printf("Do you want to continue:");
        scanf("%d",&choice);
    }while(choice!=0);
    getMSTByKursakal(edges,e,n);
    return 0;
}