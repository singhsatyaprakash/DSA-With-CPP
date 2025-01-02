#include<iostream>
#include<vector>
using namespace std;
//Recursion
int knapsackRec(vector<int>val,vector<int>wt,int W,int n){
    if(n==0 || W==0){//capacity is full or no item avaliable...
        return 0;
    }
    int itemWt=wt[n-1];
    int itemVal=val[n-1];
    if(itemWt<=W){//valid
        //include
        return max(itemVal+knapsackRec(val,wt,W-itemWt,n-1),knapsackRec(val,wt,W,n-1));
    }else{
        return knapsackRec(val,wt,W,n-1);
    }
}
//Memoization
int knapsackMem(vector<int>val,vector<int>wt,int W,int n,vector<vector<int>>&dp){
    if(n==0 || W==0){//capacity is full or no item avaliable...
        return 0;
    }
    int itemWt=wt[n-1];
    int itemVal=val[n-1];
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    if(itemWt<=W){//valid
        dp[n][W]= max(itemVal+knapsackMem(val,wt,W-itemWt,n-1,dp),knapsackMem(val,wt,W,n-1,dp));
    }else{//itemwt is more than the capacity of knapsack...
        dp[n][W]=knapsackMem(val,wt,W,n-1,dp);
    }
    return dp[n][W];
}
//Tabulation
int knapsackTab(vector<int>val,vector<int>Wt,int W,int n){
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            int itemVal=val[i-1];
            int itemWt=Wt[i-1];
            if(itemWt<=j){
                dp[i][j]=max(itemVal+dp[i-1][j-itemWt],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<"Tabluation Matrix:"<<endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Max Profit:";
    return dp[n][W];
}

int main(){
    vector<int>wt{2,5,1,3,4};
    vector<int>val{15,14,10,45,30};
    int W=7;//capacity of knapsack...
    int n=val.size();
    cout<<"Recursion:\nMaxProfit:"<<knapsackRec(val,wt,W,n)<<endl;
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    cout<<"\nMemoization:"<<endl;
    cout<<"Max Profit:"<<knapsackMem(val,wt,W,n,dp);
    cout<<"\nMemo Matrix:"<<endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nTabulation:"<<endl;  
    cout<<knapsackTab(val,wt,W,n)<<endl;
    return 0;
}