/*
Given an array (or string), the task is to reverse the array/string.

Examples:

Input: original_array[] = {1, 2, 3} Output: array_reversed[] = {3, 2, 1}

Input: original_array[] = {4, 5, 1, 2}
Output: array_reversed[] = {2, 1, 5, 4}
*/
#include<iostream>
#include<limits.h>
using namespace std;
void reverse(int arr[],int n){
    int i=0,j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverse(arr,n);
    cout<<"Reverse Array:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}