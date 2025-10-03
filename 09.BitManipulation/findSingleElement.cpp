#include<iostream>
using namespace std;
int singleNumber(int* nums, int numsSize) {
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum^=nums[i];//performing XOR because same number on performing XOR cancel out each other...
    }
    return sum;
}
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=singleNumber(arr,n);
    cout<<res<<endl;
    return 0;
}