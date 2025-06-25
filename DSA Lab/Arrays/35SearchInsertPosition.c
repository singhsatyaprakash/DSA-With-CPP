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
        mid=(low+high)/2;
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
#include<stdio.h>
int main(){
    int n;
    printf("Enter no. of elements in array:");
    scanf("%d",&n);
    //reading elements of array...
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    printf("Enter Target:");
    scanf("%d",&k);
int res=searchInsert(arr,n,k);
printf("Index Position to insert is:%d",res);
return 0;
}