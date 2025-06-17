/* Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)*/
#include<iostream>
#include<vector>
using namespace std;
int linearSearch(vector<int>arr,int key){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int n,val;
    cout<<"Enter n:";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    int key;
    cout<<"Enter key to search:";
    cin>>key;
    int idx=linearSearch(arr,key);
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