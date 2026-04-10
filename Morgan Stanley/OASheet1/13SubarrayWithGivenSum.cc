#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n=arr.size();
        int l=0,r=0;
        int sum=0;
        while(r<n){
            sum+=arr[r];
            while(sum>target){
                sum-=arr[l];
                l++;
            }
            if(sum==target){
                return {l+1,r+1};//1 based indexing
            }
            r++;
        }
        return {-1};
    }
};