/*Given an array of nonnegative integers, design an algorithm and a program to count the number
 of pairs of integers such that their difference is equal to a given key, K. */
#include<iostream>
#include<vector>
using namespace std;
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
    return 0;
}