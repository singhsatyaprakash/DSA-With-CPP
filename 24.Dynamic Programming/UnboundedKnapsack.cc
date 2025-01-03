#include<iostream>
#include<vector>
using namespace std;
int unboundedKnapsack(vector<int>val,vector<int>wt,int w,int n){
    if(w<=0){
        return 0;
    }
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<n+1;i++){
        int itemval=val[i-1];
        int itemwt=wt[i-1];
        for(int j=1;j<w+1;j++){
            if(itemwt<=j){
                dp[i][j]= max(itemval+dp[i][j-itemwt],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
    vector<int>wt{2,5,1,3,4};
    vector<int>val{15,14,10,45,30};
    int W=7;//capacity of knapsack...
    int n=val.size();
    cout<<"Max. Profit:"<<unboundedKnapsack(val,wt,W,n);
    return 0;
}