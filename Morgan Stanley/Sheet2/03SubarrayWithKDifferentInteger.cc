#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int l=0,r=0;
        int count1=0;
        while(r<n){
            mp[arr[r]]++;
            while(mp.size()>k){
                mp[arr[l]]--;
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                l++;
            }
            count1+=(r-l+1);
            r++;
        }
        mp.clear();
        l=0,r=0;
        int count2=0;
        while(r<n){
            mp[arr[r]]++;
            while(mp.size()>=k){
                mp[arr[l]]--;
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                l++;
            }
            count2+=(r-l+1);
            r++;
        }
        return count1-count2;
    }
};