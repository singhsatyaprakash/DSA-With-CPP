#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void countSort(vector<int>&arr){
    int n=arr.size();
    int max=*max_element(arr.begin(),arr.end());
    int freq[max+1]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=1;i<=max;i++){
        freq[i]=freq[i-1]+freq[i];
    }
    int temp[n];
    for(int i=n-1;i>=0;i--){
        int idx=--freq[arr[i]];
        temp[idx]=arr[i];
    }
    //printing sort sorted array
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
}
int main(){
    int n,val;
    cout<<"Enter n:";
    cin>>n;
    vector<int>arr;
    cout<<"Enter elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    countSort(arr);
    return 0;
}