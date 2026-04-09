#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string reverseWords(string &s) {
        stack<string>st;
        int n=s.size();
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                temp+=s[i];
            }
            else{
                if(temp.size()>0){
                    st.push(temp);
                }
                temp="";
            }
        }
        if(temp.size()>0){
            st.push(temp);
        }
        string ans="";
        while(!st.empty()){
            if(ans.empty()){
                ans+=st.top();
            }
            else{
                ans+='.'+st.top();
            }
            st.pop();
        }
        return ans;
    }
};