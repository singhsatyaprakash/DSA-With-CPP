#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n=s.size();
        set<char>store;
        int l=0;int r=0;
        int maxlen=1;
        while(r<n){
            while(store.find(s[r])!=store.end()){
                store.erase(s[l]);
                l++;
            }
            store.insert(s[r]);
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
