#include<bits/stdc++.h>
using namespace std;
class Solution1 {//O(n^2)..
  public:
    int maxLen(vector<int> &arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int one=0,zero=0;
            for(int j=i;j<n;j++){
                if(arr[j]==1){
                    one++;
                }
                else{
                    zero++;
                }
                if(one==zero){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
class Solution2 {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>map; //(sum,idx)
        map[0]=-1;
        int sum=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                sum+=-1;
            }
            else{
                sum+=1;
            }
            if(map.find(sum)!=map.end()){//found
                ans=max(ans,i-map[sum]);
            }
            else
                map[sum]=i;//as we are tracking largest dont update for found sum...
        }
        return ans;
    }
};