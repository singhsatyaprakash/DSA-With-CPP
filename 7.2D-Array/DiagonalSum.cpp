#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter matrix size:";
    cin>>n;
    int arr[n][n];
    cout<<"Enter elements of matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
              cin>>arr[i][j];
        }
    }
    int sum=0;
    ///O(n^n)
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(i==j){
    //             sum+=arr[i][j];
    //         }
    //         else if(j==n-1-i){
    //             sum+=arr[i][j];
    //         }
    //     }
    // }
    for(int i=0;i<n;i++){
        sum+=arr[i][i];
        if(i!=n-i-1){
            sum+=arr[i][n-1-i];
        }
    }
    cout<<"Sum of diagonal matrix is:"<<sum<<endl;
    return 0;
}