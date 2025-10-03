/*
Given an array of size N. The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.

Examples:
Input: arr[] = {3, 5, 4, 1, 9}
Output: Minimum element is: 1
        Maximum element is: 9

Input: arr[] = {22, 14, 8, 17, 35, 3}
Output: Minimum element is: 3
        Maximum element is: 35
*/
#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //finging max and miminimum of array...
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"Maximum Elemet is:"<<max<<endl;
    cout<<"Minimum Element is:"<<min<<endl;
    return 0;
}