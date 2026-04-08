#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,vector<char>>mp={
        {2,{'a','b','c'}},
        {3,{'d','e','f'}},
        {4,{'g','h','i'}},
        {5,{'j','k','l'}},
        {6,{'m','n','o'}},
        {7,{'p','q','r','s'}},
        {8,{'t','u','v'}},
        {9,{'w','x','y','z'}}
        };
    void solve(int i,int n,string digits,string temp,vector<string>&ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(auto ch:mp[digits[i]-'0']){
            solve(i+1,n,digits,temp+ch,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int n=digits.size();
        string temp="";
        solve(0,n,digits,temp,ans);
        return ans;
    }
};