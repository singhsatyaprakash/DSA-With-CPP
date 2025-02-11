#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int linearSearch(vector<int>arr,int si,int ei,int key){
    for(int i=si;i<=ei;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int jumpsort(vector<int>arr,int key){
    int window=sqrt(arr.size());
    int prev=0;
    int next=window-1;
    while(next<arr.size()){
        if(arr[next]==key){
            return next;
        }
        if(arr[next]>key){
            return linearSearch(arr,prev,next,key);
        }
        prev=next+1;
        next=next+window;
    }
    return linearSearch(arr,prev,arr.size()-1,key);
}
int main(){
    int n,val;
    cout<<"Enter n:";
    cin>>n;
    vector<int>arr;
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++){
       cin>>val;
       arr.push_back(val);
    }
    int key;
    cout<<"Enter key:";
    cin>>key;
    sort(arr.begin(),arr.end());
    int idx=jumpsort(arr,key);
    if(idx==-1){
        cout<<"Not found"<<endl;
    }else{
        cout<<"Found at index "<<idx<<endl;
    }
    return 0;
}