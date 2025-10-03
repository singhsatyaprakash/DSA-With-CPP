#include<iostream>
#include<vector>
using namespace std;
int maxRectSum(vector<vector<int>> &mat) {//O((n*m)^6)
        int m=mat.size();
        int n=mat[0].size();
        int maxSum=INT_MIN;
        for(int up=0;up<m;up++){
            for(int left=0;left<n;left++){
                for(int down=up;down<m;down++){
                    for(int right=left;right<n;right++){
                        int sum=0;
                        for(int i=up;i<=down;i++){
                            for(int j=left;j<=right;j++){
                                cout<<mat[i][j]<<" ";
                                sum+=mat[i][j];
                            }
                            cout<<endl;
                        }
                        cout<<"-------------------------"<<endl;
                        maxSum=max(maxSum,sum);
                    }
                }
            }
        }
        return maxSum;
}
int main(){
    int m,n;
    cout<<"Enter row & col:";
    cin>>m>>n;
    cout<<"Enter matrix:"<<endl;
    vector<vector<int>>mat(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int sum=maxRectSum(mat);
    cout<<"Maximum subMatrix Sum:"<<sum<<endl;
    return 0;
}
