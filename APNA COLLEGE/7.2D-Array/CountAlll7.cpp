#include<iostream>
using namespace std;
int main(){
        int n,m;
    cout<<"Enter matrix size:";
    cin>>n>>m;
    int arr[n][m];
    cout<<"Enter elements of matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
              cin>>arr[i][j];
        }
    }
    //counting 7's
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
              if(arr[i][j]==7){
                count++;
              }
        }
    }
    cout<<"Total 7's occurs is:"<< count<<" times"<<endl;
    return 0;
}