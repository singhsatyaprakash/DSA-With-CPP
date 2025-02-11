#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=1;
        int maxcount=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                count++;
                maxcount=max(maxcount,count);
            }
            else{
                count=1;
            }
        }
        return maxcount;
    }
};
int main(){
    Solution s;
    vector<int>nums={1,3,5,4,7};
    cout<<s.findLengthOfLCIS(nums);
}