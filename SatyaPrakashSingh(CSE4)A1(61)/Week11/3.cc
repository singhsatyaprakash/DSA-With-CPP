/*.Given a set of elements, you have to partition the set into two subsets such that the sum of
elements in both subsets is same. Design an algorithm and implement it using a program to solve
this problem.*/
#include<iostream>
#include<vector>
using namespace std;
bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        sum=sum/2;

        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<n+1;i++){
            dp[i][0]=true;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    if(canPartition(nums)){
        cout<<"Yes,can Partition"<<endl;
    }
    else{
        cout<<"Cannot Parition"<<endl;
    }
    return 0;
}
