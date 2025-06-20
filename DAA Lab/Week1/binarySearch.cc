/*Given an already sorted array of positive integers, design an algorithm and implement it using a
 program to find whether given key element is present in the array or not. Also, find total number
 of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binarySearch(vector<int>arr,int key){
    int si=0,ei=arr.size()-1;
    while(si<=ei){
        int mid=si+(ei-si)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(key<arr[mid]){
            ei=mid-1;
        }
        else{
            si=mid+1;
        }
    }
    return -1;
}
int main(){
    cout<<"Enter n:";
    int n,val;
    cin>>n;
    vector<int>arr;
    cout<<"Enter element:"<<endl;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    int key;
    cout<<"Enter key to search:";
    cin>>key;
    sort(arr.begin(),arr.end());
    int idx=binarySearch(arr,key);
    if(idx!=-1){
        cout<<key<<" present at index "<<idx<<"."<<endl;
    }
    else{
        cout<<"Not present."<<endl;
    }
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}