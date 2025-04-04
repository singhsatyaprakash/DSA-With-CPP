#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool issafe(int i,int j,vector<vector<char>>&grid){
    int m=grid.size();
    int n=grid[0].size();
    return i>=0 && i<m && j>=0 && j<n && grid[i][j]!='0';
}
void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1; // Mark the starting cell as visited

    // Directions for 8 possible moves
    vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, //vertical and horizontal
        {-1, 1}, {1, 1}, {1, -1}, {-1, -1} //diagnonally
    };

    while (!q.empty()) {
        pair<int, int> src = q.front();
        q.pop();

        for (auto dir : directions) {
            int new_i = src.first + dir.first;
            int new_j = src.second + dir.second;

            // Check if the new cell is safe and not visited
            if (issafe(new_i, new_j, grid) && !vis[new_i][new_j] ) {
                vis[new_i][new_j] = 1; // Mark as visited
                q.push({new_i, new_j});
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    int count=0;
    vector<vector<int>>vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(! vis[i][j] && grid[i][j]=='1'){
                bfs(grid,vis,i,j);
                count++;
            }
        }
    }
    return count;
}
int main() {
    vector<vector<char>> grid = { { '1', '1', '0', '0', '0' },
                              { '0', '1', '0', '0', '1' },
                              { '1', '0', '0', '1', '1' },
                              { '0', '0', '0', '0', '0' },
                              { '1', '0', '1', '1', '0' } };

    cout << numIslands(grid) << endl;

    return 0;
}