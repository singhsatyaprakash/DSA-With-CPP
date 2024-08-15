#include<iostream>
#include<cstring>
using namespace std;
bool ispal(char str[],int n){
    int st=0,end=n-1;
    while(st<=end){
        if(str[st++]!=str[end--]){
            cout<<"Not A Valid Palindrome"<<endl;
            return false;
        }
    }
    cout<<"Valid Palindrome."<<endl;
    return true;
}
int main(){
    char word[]="racecar";
    ispal(word, strlen(word));
    return 0;
}