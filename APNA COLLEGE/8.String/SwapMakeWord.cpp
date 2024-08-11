/*
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

Example :
Input: s1 = "bank", s2 = "kanb" Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
*/
#include<iostream>
#include<string>
using namespace std;
bool SwapAtIndices(int m,int n,string s1,string s2){
    //swapping in string s1...
        char temp=s1[m];
        s1[m]=s1[n];
        s1[n]=temp;

    //now check both string become same or not...
    if(s1.length()!=s2.length()){
        return false;
    }
    else{
        for(int i=0;i<s1.length();i++) {
            if(s1[i]!=s2[i]){
                return false;
            }
        }
    }
    return true;

}
int main(){
    string s1,s2;
    cout<<"Enter string s1:";
    getline(cin,s1);
    cout<<"Enter string s2:";
    getline(cin,s2);
    int id1,id2;//index 1 and index 2
    cout<<"Enter Index1 & Index2:";
    cin>>id1>>id2;
    bool output=SwapAtIndices(id1,id2,s1,s2);
    cout << (output ? "true" : "false") << endl;
    return 0;
}