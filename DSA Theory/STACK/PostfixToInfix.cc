#include <iostream>
#include<stack>
#include<string>
using namespace std;
bool check(char ch) {
    return (ch>='a'&& ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9');
}

string postToInfix(string s){
    stack<string>st;
    int n=s.length(); 
    for(int i=0;i<n;i++){
        if(check(s[i])){
            string op(1,s[i]);
            st.push(op);
        }else{
            if(st.size()<2){
                return "Invalid postfix expression!";
            }
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            string temp = "(" + operand1 + s[i] + operand2 + ")";
            st.push(temp);
        }
    }
    if (st.size() != 1) {
        return "Invalid postfix expression!";
    }

    return st.top();
}

int main(){
    string str;
    cout<<"Enter Postfix Expression:"<<endl;
    getline(cin,str);
    cout<<"Infix Expression"<<endl;
    cout<<postToInfix(str)<<endl;
    return 0;
}
