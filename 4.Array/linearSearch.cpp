
#include<iostream>
using namespace std;
int linearSearch(int *arr,int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter elements to search:";
    cin>>k;
    int res=linearSearch(arr,n,k);
    if(res==-1){
        cout<<"Not found."<<endl;
    }
    else{
        cout<<"Number found at "<<res<<" index "<<res+1<<"th position"<<endl;
    }
    return 0;
}