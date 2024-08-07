#include<iostream>
using namespace std;
void spiralmatrix(int arr[][100],int n,int m){//matrix ka  dimension batana complusary hai jab pointer use nahi kar rahe hai tab...
    int srow=0,scol=0;//startingRow & startingColumn
    int erow=n-1,ecol=m-1;//endingRow &endingColumn
    while(srow<=erow && scol<=ecol ){
    //top
    for(int j=scol;j<=ecol;j++){
        cout<<arr[srow][j]<<" ";
    }
    //right
    for(int i=srow+1;i<=erow;i++){
        cout<<arr[i][ecol]<<" ";
    }
    //bottom
    for(int j=ecol-1;j>=scol;j--){//once look at inequality sign at time of revision...
        if(srow==erow){//to be safe from duplicate printing
        break;
        }
        cout<<arr[erow][j]<<" ";
    }
    //left
    for(int i=erow-1;i>=srow+1;i--){
        if(scol==ecol){//to be safe from duplicate printing
        break;
        }
        cout<<arr[i][scol]<<" ";
    }
    srow++;
    erow--;
    scol++;
    ecol--;
    }
    return;
}
int main(){
    int n,m;
    cout<<"Enter the size of matrix:";
    cin>> n >> m;
    int arr[100][100];
    cout<<"Enter the elements of matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    spiralmatrix(arr,n,m);
    return 0;
}