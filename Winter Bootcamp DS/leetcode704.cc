/*Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity*/
#include<iostream>
using namespace std;
int search(int* nums, int numsSize, int target) {
    int low=0;
    int high=numsSize-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]<target){
            low=mid+1;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];
    cout<<"Enter element of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter target:";
    cin>>target;
    cout<<"Index is:"<<search(arr,n,target);
    return 0;
}