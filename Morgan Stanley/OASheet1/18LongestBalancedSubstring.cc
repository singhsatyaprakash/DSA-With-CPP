#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(unordered_map<char,int>&freq){
        int temp=freq.begin()->second;
        for(auto it:freq){
            if(it.second!=temp){
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;
                if(check(freq)){
                    maxlen=max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }
};