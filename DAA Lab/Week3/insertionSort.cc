#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>&arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        //pushing element to its position...
        while(prev>=0 && arr[prev]>curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        }
}
int main(){
    int n,val;
    cout<<"Enter n:";
    cin>>n;
    vector<int>arr;
    cout<<"Enter the elements of array:";
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    insertionSort(arr);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}