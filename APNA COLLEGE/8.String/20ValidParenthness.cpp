/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]
*/
#include<iostream>
#include<string>
using namespace std;
bool ValidParentheses(string s){
    for(char ch:s){
        if(ch=='('){
            ch
        }
    }
}
int main(){
    string s;
    cout<<"Enter String:"<<endl;
    getline(cin,s);
    bool output=ValidParentheses(s);
    cout<<(output?"true":"false")<<endl;
    return 0;
}