#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0,j=1;
    while(j<n){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
        j++;
    }
    cout<<i+1;
    return 0;
}