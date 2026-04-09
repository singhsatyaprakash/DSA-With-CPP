#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter Array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //method 1..
    vector<int>temp=arr;
    sort(temp.begin(),temp.end());

    //approach 2....
    int c0=0,c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            c0++;
        }
        else if(arr[i]==1){
            c1++;
        }
        else{
            c2++;
        }
    }
    vector<int>ans;
    for(int i=0;i<c0;i++){
        ans.push_back(0);
    }
    for(int i=0;i<c1;i++){
        ans.push_back(1);
    }
    for(int i=0;i<c2;i++){
        ans.push_back(2);
    }

    //appproach 3...
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return 0;
}