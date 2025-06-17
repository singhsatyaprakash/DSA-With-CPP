/*Given an unsorted array of integers, design an algorithm and implement it using a program to
 sort an array of elements by partitioning the array into two subarrays based on a pivot element
 such that one of the sub array holds values smaller than the pivot element while another sub
 array holds values greater than the pivot element. Pivot element should be selected randomly
 from the array. Your program should also find number of comparisons and swaps required for
 sorting the array.*/
#include<iostream>
#include<vector>
using namespace std;
void printSorted(int arr[],int n){
    cout<<"Sorted:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int partition(int arr[],int si,int ei){
    int i=si-1;
    int pivot=arr[ei];
    for(int j=si;j<ei;j++){//push all less element to starting by i positon ....
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
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}