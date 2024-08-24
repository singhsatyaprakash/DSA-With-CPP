#include<iostream>
#include<vector>
using namespace std;
void printSorted(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int partition(int arr[],int si,int ei){
    int i=si-1;
    int pivot=arr[ei];
    for(int j=si;j<ei;j++){//push all less element to staring by i positon ....
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);//pivot element get its desire position in array
    return i;//new pivot
}
void quickSort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int pivot=partition(arr,si,ei);
    quickSort(arr,si,pivot-1);//left sorting
    quickSort(arr,pivot+1,ei);//right sorting
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    printSorted(arr,n);
    return 0;
}