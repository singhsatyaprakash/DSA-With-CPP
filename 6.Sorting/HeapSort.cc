#include<iostream>
#include<vector>
using namespace std;
void heapify(int i,vector<int>&arr,int n){
    if(i>=n){
        return;
    }
    int left=2*i+1;//left child
    int right=2*i+2;//right child
    int maxI=i;//parent
    if(left<n && arr[left]>arr[maxI]){
        maxI=left;
    }
    if(right<n && arr[right]>arr[maxI]){
        maxI=right;
    }
    if(maxI!=i){
        swap(arr[i],arr[maxI]);
        heapify(maxI,arr,n);
    }
}
void heapSort(vector<int>&arr){
    int n=arr.size();
    //step1:Bulid a max heap...supoose give arr is heap...
    for(int i=(n/2)-1;i>=0;i--){
        heapify(i,arr,n);
    }
    //step2:taking elements to correct position..asscending
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i); //size of unsorted is reducing in each step..
    }
}
int main(){
    vector<int>arr={5,4,3,2,1};
    heapSort(arr);
    cout<<"Sorted:";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}