#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter matrix size:";
    ci n>>n>>m;
    int arr[n][m];
    cout<<"Enter elements of matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
              cin>>arr[i][j];
        }
    }
    //transposing a matrix
    int brr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
              brr[i][j]=arr[j][i];
              cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}