/* Given a sorted array of positive integers containing few duplicate elements, design an algorithm
 and implement it using a program to find whether the given key element is present in the array or
 not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int searchCopy(vector<int>arr,int key){
    int si=0,ei=arr.size()-1;
    int low_idx=-1,high_idx=-1;
    while(si<=ei){
        int mid=si+(ei-si)/2;
        if(arr[mid]==key){
            //search in left for lower index
            low_idx=mid;
            ei=mid-1;
        }
        else if(key<arr[mid]){
            ei=mid-1;
        }
        else{
            si=mid+1;
        }
    }
    si=0,ei=arr.size()-1;
    while(si<=ei){
        int mid=si+(ei-si)/2;
        if(arr[mid]==key){
            //search in right for higher index
            high_idx=mid;
            si=mid+1;
        }
        else if(key<arr[mid]){
            ei=mid-1;
        }
        else{
            si=mid+1;
        }
    }
    return (high_idx-low_idx)+1;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>arr;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    sort(arr.begin(),arr.end());
    int key;
    cout<<"Enter key:";
    cin>>key;
    int copies=searchCopy(arr,key);
    if(copies<0){
        cout<<"Not found."<<endl;
    }else{
        cout<<"Total "<<copies<<" of "<<key<<" found."<<endl;
    }
    return 0;
}