#include<iostream>
using namespace std;
bool isSorted(int arr[],int n,int i){
    if(i==n-1){
        return true;
    }
    else if(arr[i]>arr[i+1]){
        return false;
    }
    return isSorted(arr,n,i+1);
}
int main(){
    int arr1[]={1,2,3,4,5,6};
    int arr2[]={4,5,3,6,7,7,7};
    int arr3[]={7,7,7,7,7,7};
    cout<<isSorted(arr1,sizeof(arr1)/sizeof(arr1[0]),0)<<endl;
    cout<<isSorted(arr2,sizeof(arr2)/sizeof(arr2[0]),0)<<endl;
    cout<<isSorted(arr3,sizeof(arr3)/sizeof(arr3[0]),0)<<endl;
    return 0;
}