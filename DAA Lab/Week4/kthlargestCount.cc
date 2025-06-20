/*Given an unsorted array of integers, design an algorithm and implement it using a program to
 find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void kthLargest(vector<int>nums,int k){
    int min=*min_element(nums.begin(),nums.end());
    int max=*max_element(nums.begin(),nums.end());
    int size=max-min+1;
    int n=nums.size();
    int freq[size]={0};
    for(int i=0;i<n;i++){
        int idx=nums[i]-min;
        freq[idx]++;
    }
    for(int i=1;i<size;i++){
        freq[i]=freq[i-1]+freq[i];
    }
    int temp[n];
    for(int i=n-1;i>=0;i--){
        int idx=--freq[nums[i]-min];
        temp[idx]=nums[i];
    }
    cout<<k<<"th smallest element is:"<<temp[k-1]<<endl;
    cout<<k<<"th largest element is:"<<temp[n-k]<<endl;
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
    kthLargest(nums,k);
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}