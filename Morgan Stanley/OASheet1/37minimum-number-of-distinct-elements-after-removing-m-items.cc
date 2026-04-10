/*
Given an array of items, an i-th index element denotes the item id's, and given a number m, the task is to remove m elements such that there should be minimum distinct id's left. Print the number of distinct id's.
*/
#include <bits/stdc++.h>
using namespace std;
//approach 1....
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

// approach 2...
int distinctIds(vector<int>arr, int k){
    int n=arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    priority_queue<int, vector<int>, greater<int> > pq;//min heap.. having less freq remove them...

    for (auto it : mp) {
        pq.push(it.second);
    }

    while (k > 0) {
        k -= pq.top();
        if (k >= 0)
            pq.pop();
    }

    return pq.size();
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
