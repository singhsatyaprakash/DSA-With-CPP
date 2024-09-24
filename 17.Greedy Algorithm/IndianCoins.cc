#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MinCoinMakeChange(vector<int>coins,int amount){
    int n=coins.size();
    //sort on basis of desecding order..
    sort(coins.begin(),coins.end(),greater<int>());
    int ans=0;
    for(int i=0;i<n && amount>0;i++){
        if(amount>=coins[i]){
            // ans++;
            // cout<<coins[i]<<"--->1"<<endl;
            // amount-=coins[i];
            // i--;
            ans+=amount/coins[i];
            amount=amount%coins[i];
        }
    }
    return ans;
}
int main(){
    int n;
    vector<int>coins={1,2,5,10,20,50,100,500,2000};
    int amount;
    cout<<"Enter ammount to change:";
    cin>>amount;
    int res=MinCoinMakeChange(coins,amount);
    cout<<"Minimum \""<<res<<"\" coins need to make change."<<endl;
    return 0;
}