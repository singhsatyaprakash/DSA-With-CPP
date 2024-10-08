#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
void topMaxheap(){
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(11);
    pq.push(9);
    pq.push(31);
    pq.push(52);

    while(!pq.empty()){
        cout<<"Top value:"<<pq.top()<<endl;
        pq.pop();
    }
}
void topMinHeap(){
    priority_queue<int>pq;
    pq.push(11);
    pq.push(9);
    pq.push(31);
    pq.push(52);

    while(!pq.empty()){
        cout<<"Top value:"<<pq.top()<<endl;
        pq.pop();
    }
}
int main(){
    cout<<"\n***TOP MAX HEAP***"<<endl;
    topMaxheap();
    cout<<"\n\n***TOP MIN HEAP***"<<endl;
    topMinHeap();
    return 0;
}