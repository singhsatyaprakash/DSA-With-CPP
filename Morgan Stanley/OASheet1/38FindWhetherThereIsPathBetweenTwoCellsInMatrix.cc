/*
Given N X N matrix filled with 1, 0, 2, 3. Find whether there is a path possible from source to destination, traversing through blank cells only. You can traverse up, down, right, and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there are an only a single source and single destination(sink).
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<pair<int,int>>directions={{-1,0},{0,1},{1,0},{0,-1}};
    // Function to find whether a path exists from the source to destination.
    bool dfs(int row,int col,int n,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        if(grid[row][col]==2){
            return true;
        }
        vis[row][col]=true;
        for(auto dir:directions){
            int nrow=row+dir.first;
            int ncol=col+dir.second;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]!=0){
                if(dfs(nrow,ncol,n,grid,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vector<vector<bool>>vis(n,vector<bool>(n,false));
                    return dfs(i,j,n,grid,vis);
                }
            }
        }
        return false;
    }
};
