#include<iostream>
#include<vector>
using namespace std;

void heapify(int arr[],int n,int i){
    int parent=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[left]>arr[parent]){
        parent=left;
    }
    if(right<=n && arr[right]>arr[parent]){
        parent=right;
    }
    if(parent!=i){
        swap(arr[parent],arr[i]);
        heapify(arr,n,parent);
    }
}

void heapSort(int arr[],int n){
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
    //heapsort
    for(int i=n;i>1;i--){
        swap(arr[i],arr[1]);
        heapify(arr,i-1,1);
    }
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n+1];
    cout<<"Enter elements:";
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    heapSort(arr,n);
    cout<<"Sorted array:";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}