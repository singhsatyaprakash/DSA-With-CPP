/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.*/
#include<iostream>
using namespace std;
int searchInsert(int* nums, int numsSize, int target) {

    if(target>nums[numsSize-1]){
        return numsSize;
    }
    else if(target<nums[0]){
        return 0;
    }
    else{
    //binary search in array..
    int low=0,high=numsSize-1;
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
    }
    return low;
    }
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
    cout<<"Insert position is:"<<searchInsert(arr,n,target);
    return 0;
}