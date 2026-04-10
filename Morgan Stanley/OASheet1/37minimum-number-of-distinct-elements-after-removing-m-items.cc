/*
Given an array of items, an i-th index element denotes the item id's, and given a number m, the task is to remove m elements such that there should be minimum distinct id's left. Print the number of distinct id's.
*/
#include <bits/stdc++.h>
using namespace std;

int distinctIds(vector<int>arr,int m){
    int n=arr.size();
    unordered_map<int, int> mp;
    vector<pair<int, int> > v;
    int count = 0;

    for (int i = 0; i < n; i++){
        mp[arr[i]]++;
    }

    for (auto it :mp)
        v.push_back({it.second,it.first});


    sort(v.begin(), v.end());//based on freq

    int size = v.size();

    for (int i = 0; i < size; i++) {

        if (v[i].first <= m) {
            m -= v[i].first;
            count++;
        }

        // Return the remaining size
        else
            return size - count;
    }
    return size - count;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cout<<"Enter m:";
    cin>>m;
    cout<<distinctIds(arr,m);
    return 0;
}
