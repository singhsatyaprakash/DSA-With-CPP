/*
You have a set of integers, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.
Example :
Input: nums = [1,2,2,4] Output: [2,3]
*/
#include<iostream>
#include<vector>
using namespace std;
// vector<int> findingNumber(vector<int> nums){
//     vector<int> ans;
//     for(int i=0;i<nums.size();i++){
//         if(nums[i]==nums[i+1]){
//             ans.push_back(nums[i]);
//             ans.push_back(nums[i]+1);
//         }
//     }
//     return ans;
// }
vector<int> findingNumber(vector<int>& nums) {
vector<int> ans;
int n = nums.size();
cout<<n<<endl;
vector<bool> isPresent(n+1, false);
for(int i=0; i<n; i++) {
if(isPresent[nums[i]]) {
ans.push_back(nums[i]);
}
isPresent[nums[i]] = true;
}
for(int i=1; i<isPresent.size(); i++) {
if(!isPresent[i]) {
ans.push_back(i);
break;
}
}
return ans;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>nums(n);
    //set of integer
    cout<<"Enter set of integers:\n";
    for(int i=0;i<nums.size();i++){
        cin>>nums[i];
    }
    vector<int> ans=findingNumber(nums);
    cout<<ans[0]<<","<<ans[1]<<endl;
    return 0;
}