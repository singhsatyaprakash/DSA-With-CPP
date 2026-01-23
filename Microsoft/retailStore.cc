#include<iostream>
#include<vector>
using namespace std;
void dfs(int row,int col,vector<vector<bool>>&vis,vector<vector<int>>&mat,vector<vector<int>>&ans,int dis,int k){
    vis[row][col]=true;
    int m=mat.size();
    int n=mat[0].size();
    vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    for(auto dir:directions){
        int nrow=row +dir.first;
        int ncol=col+dir.second;
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && mat[nrow][ncol]!=1 && !vis[nrow][ncol] && dis+1<=k){
            ans[nrow][ncol]++;
            dfs(nrow,ncol,vis,mat,ans,dis+1,k);
        }
    }

}
int main(){
    cout<<"Enter size of matrix:";
    int m,n;
    cin>>m>>n;
    vector<vector<int>>mat(m,vector<int>(n));
    cout<<"Enter matrix:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int k;
    cout<<"Enter max distance to be of houses from store:";
    cin>>k;

    //solution
    vector<vector<int>>houses;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                houses.push_back({i,j});
            }
        }
    }

    //apply dfs upto k distance for all points

    int totalhouses=houses.size();

    
    vector<vector<int>>ans(m,vector<int>(n,0));//decrese val that much time visiting...
    for(auto it:houses){
        int row=it[0];
        int col=it[1];
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        dfs(row,col,vis,mat,ans,0,k);
    }
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(ans[i][j]==totalhouses){
                count++;
            }
        }
    }
    cout<<"Possible location count are:"<<count<<endl;
    return 0;

}76