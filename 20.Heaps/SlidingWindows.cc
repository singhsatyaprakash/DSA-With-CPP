#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;
void slidingWindow(vector<int>arr,int k){
    priority_queue<pair<int,int>>pq;//(arr,idx)
    //1st Window
    for(int i=0;i<k;i++){
        pq.push(make_pair(arr[i],i));
    }
    cout<<"Output:"<<pq.top().first<<" ";
    //for next
    for(int i=k;i<arr.size();i++){
        //if top element is not from window pop it..
        while(!pq.empty() && pq.top().second<=(i-k)){
            pq.pop();
        }
        pq.push(make_pair(arr[i],i));
        cout<<pq.top().first<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>arr{1,3,-1,-3,5,3,6,7};
    int k=3;
    slidingWindow(arr,k);
    return 0;
}