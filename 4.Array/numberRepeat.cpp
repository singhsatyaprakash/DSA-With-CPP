/*Question 1 : Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct. [link]
Examples :
Input: nums = [1,2,3,4]
Output: false
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/
#include<iostream>
using namespace std;
bool check(int *nums,int n){
    bool a=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j]){
                a=true;
                return a;
            }
        }
    }
    return false;
}
int main(){
    int n;
    //how many elements in given array...
    cin>>n;
    int nums[n];
    //enter the elements of array...
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    bool a;
    a=check(nums,n);
    cout<<a<<endl;
    return 0;
}
