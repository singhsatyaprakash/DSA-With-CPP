#include<iostream>
#include<vector>
using namespace std;
void genrateAllPermutations(vector<int>&nums,int idx,vector<vector<int>>&ans){
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        genrateAllPermutations(nums,idx+1,ans);
        swap(nums[idx],nums[i]); //reset nums array;
    }
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter element of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>ans;
    genrateAllPermutations(nums,0,ans);
    cout<<"All permutations:"<<endl;
    int count=0;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        count++;
        cout<<endl;
    }

    cout<<"Total:"<<count<<endl;
    return 0;
}
