/*Given an unsorted array of integers, design an algorithm and a program to sort the array using
insertion sort. Your program should be able to find number of comparisons and shifts ( shifts 
total number of times the array elements are shifted from their place) required for sorting the
array.*/
#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>&arr){
    int n=arr.size();
    int count=0;
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        //pushing element to its position...
        while(prev>=0 && arr[prev]>curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
            count++;
        }
    }
    cout<<"Comparisons:"<<count<<endl;
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
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}