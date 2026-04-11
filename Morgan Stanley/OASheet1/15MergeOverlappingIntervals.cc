#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int a1=intervals[0][0];
        int b1=intervals[0][1];
        for(int i=1;i<n;i++){
            int a2=intervals[i][0];
            int b2=intervals[i][1];
            if(max(a1,a2)<=min(b1,b2)){//overlapping...
                a1=min(a1,a2);
                b1=max(b1,b2);
            }
            else{
                ans.push_back({a1,b1});
                a1=a2;
                b1=b2;
            }
        }
        ans.push_back({a1,b1});
        return ans;
    }
};