#include<iostream>
using namespace std;
int binarySearch(int arr[],int si,int ei,int target){
    while(si<=ei){
        int mid=si+(ei-si)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(target<arr[mid]){
            ei=mid-1;
        }
        else{
            si=mid+1;
        }
    }
    return -1;
}
int expoSearch(int arr[],int n,int target){
    int prev=0;
    int next=1;
    int power=1;
    while(next<n){
        if(arr[next]==target){
            return next;
        }
        if(arr[next]>target){
            return binarySearch(arr,prev,next,target);
        }
        prev=next+1;
        power++;
        power=power*2;
        next=prev+power-1;
    }
    return binarySearch(arr,prev,n-1,target);
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
    int target;
    cout<<"Enter target:";
    cin>>target;
    int idx=expoSearch(arr,n,target);
    if(idx==-1){
        cout<<"Not found"<<endl;
    }else{
        cout<<"Found at index "<<idx<<endl;
    }
    return 0;
}