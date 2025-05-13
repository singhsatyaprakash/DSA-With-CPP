#include<iostream>
#include<vector>
using namespace std;
// int LCSlength(string str1,string str2,int n,int m){
//     if(n==0 || m==0){
//         return 0;
//     }
//     if(str1[n-1]==str2[m-1]){
//         return 1+LCSlength(str1,str2,n-1,m-1);
//     }
//     else{
//         return max(LCSlength(str1,str2,n-1,m),LCSlength(str1,str2,n,m-1));
//     }

// }

int lcsRec(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    if(n==0 || m==0){
        return 0;
    }
    if(str1[n-1]==str2[m-1]){
        return 1+lcsRec(str1.substr(0,n-1),str2.substr(0,m-1));
    }
    else{
        int ans1=lcsRec(str1.substr(0,n-1),str2);
        int ans2=lcsRec(str1,str2.substr(0,m-1));
        return max(ans1,ans2);
    }
}

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

    //Recursion...
    // int length=LCSlength(str1,str2,str1.size(),str2.size());
    int length=lcsRec(str1,str2);
    cout<<"Length of Longest common subsequqence is:"<<length<<endl;

    //Memorization...
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dpm(n+1,vector<int>(m+1,-1));
    cout<<"Length:"<<lcsMem(str1,str2,dpm);
    cout<<"\nMemorization matrix:"<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dpm[i][j]<<" ";
        }
        cout<<endl;
    }
    ///Tabulation
    cout<<"Tabulation:"<<endl;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]= 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<"LENGTH:"<<dp[n][m];
    cout<<"\nTabulation Matrix:"<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
