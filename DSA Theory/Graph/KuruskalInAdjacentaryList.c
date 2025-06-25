#include<stdio.h>
typedef struct node{
    int dst,wt;
    struct node* next;
}tree_type;
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
void addEdgeInAscendingOrder(tree_type* source[],int src,int dst,int wt){
    tree_type* newnode=(tree_type*)malloc(sizeof(tree_type));
    newnode->dst=dst;
    newnode->wt=wt;
    if(source[src]==NULL || source[src]->wt >=newnode->wt){//insert at front
        newnode->next=source[src];
        source[src]=newnode;
        return;
    }
    tree_type* curr=source[src];
    while(curr->next!=NULL && curr->next->wt < newnode->wt){
        curr=curr->next;
    }
    newnode->next=curr->next;
    curr->next=newnode;
    return;
}
void getMSTByKursakal(tree_type* source[],int V){
    int par[V],rank[V];
    for(int i=0;i<V;i++){
        par[i]=i;
        rank[i]=0;
    }
    
}
int main(){
    int V;
    printf("Enter number of vertices:");
    scanf("%d",&V);
    tree_type* source[V];
    int choice;
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int src,dst,wt;
                printf("Enter (src,dst,wt):");
                scanf("%d%d%d",&src,&dst,&wt);
                addEdgeInAscendingOrder(source,src,dst,wt);
                break;
            }
            case 2:{
                getMSTByKursakal(source,V);
            }
        }
    }
}