#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void countSort(vector<int>&arr,int div){
    int n=arr.size();
    int freq[10]={0};
    for(int i=0;i<n;i++){
        int num=(arr[i]/div)%10;
        freq[num]++;
    }
    for(int i=1;i<=9;i++){
        freq[i]=freq[i-1]+freq[i];
    }
    int temp[n];
    for(int i=n-1;i>=0;i--){
        int num=(arr[i]/div)%10;
        int idx=--freq[num];
        temp[idx]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
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
    int max=*max_element(arr.begin(),arr.end());
    for(int i=1;max/i>0;i*=10){
        countSort(arr,i);
    }

    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}