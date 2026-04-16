#include<bits/stdc++.h>
using namespace std;
//freq of all character in substring must be same...
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

class Solution2 {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int distinct = 0;
            int maxFreq = 0;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';

                if (freq[idx] == 0) distinct++;
                freq[idx]++;

                maxFreq = max(maxFreq, freq[idx]);

                int len = j - i + 1;

                // check balanced condition
                if (len == distinct * maxFreq) {
                    maxlen = max(maxlen, len);
                }
            }
        }

        return maxlen;
    }
};