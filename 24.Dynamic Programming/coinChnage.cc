#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>coins{1,2,5};
    int amount=5;
    vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
    for(int i=0;i<coins.size()+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<coins.size()+1;i++){
        int coin=coins[i-1];
        for(int j=1;j<amount+1;j++){
            if(coin<=j){
                dp[i][j]=dp[i][j-coin]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<"Total no. of ways:"<<dp[coins.size()][amount];
    cout<<endl;
    cout<<"Dp Matrix:"<<endl;
    for(int i=0;i<coins.size()+1;i++){
        for(int j=0;j<amount+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}