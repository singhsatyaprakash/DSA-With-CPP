#include<iostream>
#include<vector>
using namespace std;
int coinChangeRec(vector<int>&coins,int amount,int n){
    if(amount==0){
        return 1;
    }
    if(n<=0){
        return 0;
    }
    if(coins[n-1]>amount){
        //skip
        return coinChangeRec(coins,amount,n-1);
    }
    else{
        return coinChangeRec(coins,amount-coins[n-1],n)//we can select it many time so no reduce in n
         +coinChangeRec(coins,amount,n-1);
    }
}
int main(){
    int n;
    cout<<"Enter no. of coins:";
    cin>>n;
    cout<<"Enter cost of coins:"<<endl;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int amount;
    cout<<"Enter amount:";
    cin>>amount;
    cout<<"Total no. of ways:"<<coinChangeRec(coins,amount,n);
    return 0;
}