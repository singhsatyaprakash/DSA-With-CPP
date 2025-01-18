#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>&nums,int si,int mid,int ei){
        int i=si;
        int j=mid+1;
        vector<int>ans;
        while(i<=mid && j<=ei){
            if(nums[i]<=nums[j]){
                ans.push_back(nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            ans.push_back(nums[i++]);
        }
        while(j<=ei){
            ans.push_back(nums[j++]);
        }
        int x=0;
        for(int idx=si,x=0;idx<=ei;idx++){
            nums[idx]=ans[x++];
        }
    }
    void mergesort(vector<int>&nums,int si,int ei){
        if(si>=ei){
            return;
        }
        int mid=si+(ei-si)/2;
        mergesort(nums,si,mid);
        mergesort(nums,mid+1,ei);
        merge(nums,si,mid,ei);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};
int main(){
    vector<int>nums={5,46,24,78,9,3,2,1,87};
    Solution s;
    vector<int>ans;
    ans=s.sortArray(nums);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}