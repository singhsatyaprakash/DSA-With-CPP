#include<iostream>
#include<bits/stdc++.h>  
using namespace std;
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
    //brute force...
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    //better...sort the array with (element,idx)...apply binary search...
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({arr[i],i});
    }
    sort(v.begin(),v.end());
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[low].first+v[high].first==target){
            cout<<v[low].second<<" "<<v[high].second<<endl;
            break;
        }
        if(v[low].first+v[high].first<target) low++;
        else high--;
    }

    //optimal approach...
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        if(m.find(target-arr[i])!=m.end()){
            cout<<m[target-arr[i]]<<" "<<i<<endl;
        }
        m[arr[i]]=i;
    }
    return 0;
}
