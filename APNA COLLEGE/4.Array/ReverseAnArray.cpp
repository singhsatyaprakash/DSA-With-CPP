
#include<iostream>
using namespace std;
int main(){
int arr[]={5,4,6,7,8,9};
int n=sizeof(arr)/sizeof(int);
int copyarr[n];
for(int i=0;i<n;i++){
     int j=n-i-1;
    copyarr[i]=arr[j];
}
for(int i=0;i<n;i++){
    cout<<copyarr[i]<< "  ";
}
    return 0;
}