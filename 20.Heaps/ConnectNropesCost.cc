#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int connectNrope(vector<int>ropes){
    priority_queue<int,vector<int>,greater<int>>pq(ropes.begin(),ropes.end());//min heap
    int cost=0;
    while(pq.size()>1){
        int min1=pq.top();
        pq.pop();
        int min2=pq.top();
        pq.pop();
        cost+=min1+min2;
        pq.push(min1+min2);
    }
    return cost;
}
int main(){
    vector<int>rope1={4,3,2,6};
    vector<int>rope2={1,2,5};
    int res1=connectNrope(rope1);
    int res2=connectNrope(rope2);
    cout<<"Cost of set 1:$"<<res1<<endl;
    cout<<"Cost of set 2:$"<<res2<<endl;
    return 0;
}