#include<iostream>
using namespace std;
int search(int arr[],int si,int ei,int target){
    if(si>ei){
        return -1;//not found..
    }
    int mid=si+(ei-si)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(arr[si]<=arr[mid]){//line 1
        if(arr[si]<target && target<arr[mid]){//leftsearch
            return search(arr,si,mid-1,target);
        }
        else{
            return search(arr,mid+1,ei,target);
        }
    }
    else{//line 2
    if(arr[si]<=arr[mid]){//line 1
        if(arr[mid]<target && target<arr[ei]){//leftsearch
            return search(arr,mid+1,ei,target);
        }
        else{
            return search(arr,si,mid-1,target);
        }
    }
}
}
int main(){
    int n;
    cout<<"Enter the size of matrix:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter element to search:"<<endl;
    cin>>target;
    cout<<"Idx:"<<search(arr,0,n-1,target)<<endl;
    return 0;
}