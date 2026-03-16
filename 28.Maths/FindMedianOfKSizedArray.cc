#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
void findMedian(vector<int>&nums,int k){
    int n=nums.size();
    for(int i=0;i<=n-k;i++){
        vector<int>temp(nums.begin()+i,nums.begin()+i+k);
        sort(temp.begin(),temp.end());
        int len=temp.size();
        if(len%2==0){
            cout<<temp[len/2-1]<<" ";
        }
        else{
            cout<<temp[len/2]<<" ";
        }
    }
}
void findMedianMultiSet(vector<int>&nums,int k){
    int n=nums.size();
    int i=0,j=0;
    multiset<int>left,right; ///red-black tree...self balancing tree...
    while(j<n){
        if(left.empty() || left.size()<=right.size()){
            left.insert(nums[j]);
        }
        else{
            right.insert(nums[j]);
        }
        //adjustment or balancing...
        if(!right.empty()){
            int leftMax=*left.rbegin();
            int rightMin=*right.begin();
            if(leftMax>rightMin){
                left.erase(leftMax);
                right.erase(rightMin);
                left.insert(rightMin);
                right.insert(leftMax);
            }
        }
        if(j-i+1==k){
            //find median and print it...
            cout<<*left.rbegin()<<" ";
    
            //remove the element going out of window...
            if(left.find(nums[i])!=left.end()){//found in left...
                left.erase(nums[i]);
            }
            else{
                right.erase(nums[i]);
            }
            i++;
        }
        j++;
    }
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter array:"<<endl;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    //size of subarray to take....
    int k;
    cout<<"Enter k:";
    cin>>k;
    //find median of each k sized subarray and print it...

    //navie Approach...
    //O(n*k*logk)
    findMedian(nums,k);
    cout<<"------------------------------------"<<endl;

    //O(nlogk)
    findMedianMultiSet(nums,k);   


    return 0;
}