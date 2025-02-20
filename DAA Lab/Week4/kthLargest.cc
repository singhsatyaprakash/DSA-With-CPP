#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int kthLargestElement(vector<int>nums,int k){
    priority_queue<int,vector<int>,greater<int>>minheap;
    for(int num:nums){
        minheap.push(num);
        if(minheap.size()>k){
            minheap.pop();
        }
    }
    return minheap.top();
}
int main(){
    int n,val;
    cout<<"Enter n:";
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        cin>>val;
        nums.push_back(val);
    }
    int k;
    cout<<"Enter k:";
    cin>>k;
    int res=kthLargestElement(nums,k);
    cout<<k<<"th largest element is:"<<res;
    return 0;
}