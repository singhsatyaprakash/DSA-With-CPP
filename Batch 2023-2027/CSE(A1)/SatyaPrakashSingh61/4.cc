/*
Write a C++ program to sort a given array of 0s, 1s and 2s. In the final array put all 0s first, then all 1s and all 2s in last.
*/
#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return;
}
void mergeArray(int arr1[], int size1, int arr2[], int size2, int mergedArray[]) {
    for(int i=0;i<size1;i++){
        mergedArray[i]=arr1[i];
    }
    for(int i=0;i<size2;i++){
        mergedArray[size1+i]=arr2[i];
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr1[]={0,1,2,2,1,1,0,0,1};
    int arr2[]={0,1,2,2,1,1,0,0,1};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Array 1:"<<endl;
    printArray(arr1,size1);
    cout<<"Array 2:"<<endl;
    printArray(arr2,size2);
    int newSize=size1+size2;
    int arr[newSize];
    mergeArray(arr1,size1,arr2,size2,arr);
    bubbleSort(arr,newSize);
    cout<<"Merge and sorted array:"<<endl;
    printArray(arr,newSize);
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}