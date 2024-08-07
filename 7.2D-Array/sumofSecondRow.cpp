#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter matrix size:";
    cin>>n>>m;
    int arr[n][100];
    cout<<"Enter elements of matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
              cin>>arr[i][j];
        }
    }
    // sum of second row matrix pointer...
    int sum=0;
    for(int j=0;j<m;j++){
        sum+=*(*(arr+1)+j);
    }
    cout<<"Sum of second row is:"<<sum<<endl;
    return 0;
}