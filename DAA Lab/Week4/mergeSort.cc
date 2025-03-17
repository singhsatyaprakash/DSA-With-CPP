/*Given an unsorted array of integers, design an algorithm and implement it using a program to
 sort an array of elements by dividing the array into two subarrays and combining these subarrays
 after sorting each one of them. Your program should also find number of comparisons and
 inversions during sorting the array*/
#include<iostream>
#include<vector>
using namespace std;
void printSorted(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void merge(int arr[],int si,int mid,int ei){
    vector<int>temp;
    int i=si;
    int j=mid+1;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
        temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }
    //copy to original array..
    for(int idx=si,x=0;idx<=ei;idx++){
        arr[idx]=temp[x++];
    }
}
void mergeSort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;
    mergeSort(arr,si,mid);//left half
    mergeSort(arr,mid+1,ei);//right half
    merge(arr,si,mid,ei);//conquer: Merge the two halves
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
    mergeSort(arr,0,n-1);
    printSorted(arr,n);
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}