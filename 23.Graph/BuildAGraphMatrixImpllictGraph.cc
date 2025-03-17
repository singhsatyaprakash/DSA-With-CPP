#include<iostream>
#include<vector>
using namespace std;
int main(){
    int v,src,dst;
    cout<<"Enter number of vertices:"<<endl;
    cin>>v;
    vector<vector<int>>graph(v,vector<int>(v,0));
    int choice;
    do{
        cout<<"Enter (src,dest):";
        cin>>src>>dst;
        if(src>v-1 || dst>v-1 || src<0 ||dst<0){
            cout<<"Invalid edge enter."<<endl;
            continue;
        }
        graph[src][dst]=1;
        graph[dst][src]=1;
        cout<<"Press 0 to exist:";
        cin>>choice;
    }while(choice!=0);

    cout<<"Graph:"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
