#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool IsValid(string str){
    stack<char>s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch=='['||ch=='{'||ch=='('){
            s.push(ch);// Push opening brackets
        }
        else{//agar closing aa gaya edge case.. // Closing bracket handling
            if(s.empty()){
                return false;
            }
            //matching..
            char top=s.top();
            if((top=='('&& ch==')')||(top=='{'&& ch=='}')||(top=='['&& ch==']')){
                s.pop();// Pop if matching pair found
            }
            else{
                return false;// Mismatch
            }
        }
    }
    return s.empty();
}
int main(){
    cout<<"Enter string:";
    string str;
    getline(cin,str);
    bool res=IsValid(str);
    if(res){
        cout<<"Valid"<<endl;
    }else{
        cout<<"Not  valid."<<endl;
    }
    return 0;
}