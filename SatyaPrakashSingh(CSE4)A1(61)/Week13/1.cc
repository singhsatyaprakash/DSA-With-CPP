/*Given an array of characters, you have to find distinct characters from this array. Design an
algorithm and implement it using a program to solve this problem using hashing.*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter no: of character:";
    cin>>n;
    vector<char>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<char,int>map;
    for(auto it:arr){
        map[it]++;
    }
    cout<<"List:"<<endl;
    for(auto it:map){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}