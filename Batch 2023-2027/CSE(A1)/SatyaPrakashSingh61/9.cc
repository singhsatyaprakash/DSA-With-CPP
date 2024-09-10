/*
Write a C++ program to find the maximum occurring character in a string.
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter string:";
    getline(cin,str);
    int arr[26]={0};
    int n=str.size();
    for(int i=0;i<n;i++){
        int idx=str[i]-'a';
        arr[idx]++;
    }
    int max=INT_MIN;
    for(int i=0;i<26;i++){
        if(arr[i]<max){
            max=arr[i];
        }
    }
    char ch=max+'a';
    cout<<"Most occuring character is:"<<ch<<endl;
    return 0;
}