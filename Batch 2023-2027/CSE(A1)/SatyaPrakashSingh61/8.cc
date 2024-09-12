/*
Write C++ program to reverse each word of string.
*/
#include<iostream>
#include<string>
using namespace std;
// Function to reverse a single word
string reverseWord(string str,int start,int end){
    while(start<end){
        swap(str[start],str[end]);
        start++;
        end--;
    }
    return str;
}

int main(){
    string str;
    cout<<"Enter string:";
    getline(cin,str);
    int n=str.size();
    int start=0;
    // Traverse through the string and reverse each word
    for(int i=0;i<=n;i++){
        // If we encounter a space or the end of the string, reverse the word
        if(i==n || str[i]==' '){
            str=reverseWord(str,start,i-1);//string is pass by value..
            start=i+1;//Move to the next word first letter
        }
    }
    cout<<"Reversed words string: "<<str<<endl;
    return 0;
}
