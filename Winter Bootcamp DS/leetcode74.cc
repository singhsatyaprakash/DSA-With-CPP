#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0;
        int high=m*n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int i=mid/n; //divide by no. of columns
            int j=mid%n; //modulus by no. of columns
            if(matrix[i][j]==target){
                return true;
            }
            if(target<matrix[i][j]){
                high=mid-1;
            }
            else if(target>matrix[i][j]){
                low=mid+1;
            }
        }
        return false;
    }
};
int main(){
    vector<vector<int>>matrix={{1,4,5},
                               {9,13,17},
                               {21,23,27}};
    cout<<"Enter target:";
    int target;
    cin>>target;
    Solution s;
    if(s.searchMatrix(matrix,target)){
        cout<<"Found."<<endl;
    }
    else{
        cout<<"Not Found."<<endl;
    }
    return 0;
}