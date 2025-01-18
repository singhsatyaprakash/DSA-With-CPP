#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int helper(vector<int>&nums,int si,int ei,int target){
        if(si>ei){
            return -1;
        }
        int mid=si+(ei-si)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[si]<=nums[mid]){ //got sorted part
            if(nums[si]<=target && target<=nums[mid]){
                return helper(nums,si,mid-1,target);
            }
            else{
                return helper(nums,mid+1,ei,target);
            }
        }
        else{
            if(nums[mid]<=target && target<=nums[ei]){
                return helper(nums,mid+1,ei,target);
            }
            else{
                return helper(nums,si,mid-1,target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return helper(nums,0,nums.size()-1,target);
    }
};
int main(){
    Solution s;
    vector<int>nums={4,5,6,7,8,1,2,3};
    cout<<"Enter target:";
    int target;
    cin>>target;
    int res=s.search(nums,target);
    cout<<"Index is:"<<res;
    return 0;
}