#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            if(m.count(tolower(s[i]))){
                m[tolower(s[i])]++;
            }
            else{
                m[tolower(s[i])]=1;
            }
        }
        for(int i=0;i<t.size();i++){
            if(m.count(tolower(t[i]))==0){
                return false;
            }
            m[tolower(t[i])]--;
            if(m[tolower(t[i])]==0){
                m.erase(tolower(t[i]));
            }
        }
        return m.size()==0;
    }
};

class Solution2{
public:
    bool isAnagram(string s, string t) {
        vector<int>valid(26,0);
        for(auto ch:s){
            valid[ch-'a']++;
        }
        for(auto ch:t){
            valid[ch-'a']--;
        }
        for(int i=0;i<26;i++){
            if(valid[i]!=0){
                return false;
            }
        }
        return true;
    }
};