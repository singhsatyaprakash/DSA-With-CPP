#include<iostream>
#include<vector>
using namespace std;

int lcsMem(string str1,string str2,vector<vector<int>>&dp){
    int n=str1.size();
    int m=str2.size();
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(str1[n-1]==str2[m-1]){
        dp[n][m]= 1+lcsMem(str1.substr(0,n-1),str2.substr(0,m-1),dp);
    }
    else{
        int ans1=lcsMem(str1.substr(0,n-1),str2,dp);
        int ans2=lcsMem(str1,str2.substr(0,m-1),dp);
        dp[n][m]= max(ans1,ans2);
    }
    return dp[n][m];
}
int main(){
    string str1,str2;
    cout<<"Enter string1:";
    getline(cin,str1);
    cout<<"Enter string2:";
    getline(cin,str2);

    //Memorization...
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dpm(n+1,vector<int>(m+1,-1));
    cout<<"Length:"<<lcsMem(str1,str2,dpm);
    return 0;
}
