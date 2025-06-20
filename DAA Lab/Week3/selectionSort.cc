/*Given an unsorted array of integers, design an algorithm and implement a program to sort this
 array using selection sort. Your program should also find number of comparisons and number of
 swaps required.*/
#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int>&arr){
    int n=arr.size();
    int swapcount=0,comparsion=0;
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            comparsion++;
            if(arr[min_idx]>arr[j]){
                min_idx=j;
            }
        }
        if(min_idx!=i){
            swapcount++;
            swap(arr[min_idx],arr[i]);
        }
    }
    cout<<"Comparsion = "<<comparsion<<endl;
    cout<<"Swap = "<<swapcount<<endl;
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
    selectionSort(arr);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}