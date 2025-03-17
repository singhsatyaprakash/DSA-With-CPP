/*Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int CountDifferencePair(vector<int>arr,int k){
    int n=arr.size();
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    int count=0;
    for(auto p:m){
        if( k && m.count(p.first+k) || k==0 && p.second>1){ //unique pair
            count++;
        }
    }
    return count;
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
    int k;
    cout<<"Enter k:";
    cin>>k;
    int res=CountDifferencePair(arr,k);
    cout<<"Total pairs are:"<<res<<endl;
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}