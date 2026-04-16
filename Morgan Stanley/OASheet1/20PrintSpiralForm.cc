#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        int left=0,right=m-1;
        int top=0,down=n-1;
        while(left<=right && top<=down){
            for(int j=left;j<=right;j++){
                ans.push_back(mat[top][j]);
            }
            top++;
            if(top>down) break;

            for(int i=top;i<=down;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            if(left>right) break;

            for(int j=right;j>=left;j--){
                ans.push_back(mat[down][j]);
            }
            down--;
            if(top>down) break;

            for(int i=down;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
        return ans;
    }
};