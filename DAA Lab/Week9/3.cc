#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int computeCost(vector<int>&files){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<files.size();i++){
        pq.push(files[i]);
    }
    int cost=0;
    while(pq.size()>1){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        int total=first+second;
        cost+=total;
        pq.push(total);
    }
    return cost;
}
int main(){
    int n;
    cout<<"How many files:";
    cin>>n;
    vector<int>files(n);
    for(int i=0;i<n;i++){
        cin>>files[i];
    }
    int cost=computeCost(files);
    cout<<"Minimum cost:"<<cost<<endl;
    return 0;
}