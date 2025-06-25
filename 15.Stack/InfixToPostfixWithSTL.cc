#include<iostream>
#include<string>
#include<stack>
using namespace std;
int pres(char c){
    switch(c){
        case '+': return 1;
        case '-': return -1;
        case '*': return 2;
        case '/': return -2;
    }
}
char oper(int a){
    switch(a){
        case 1: return '+';
        case -1: return '-';
        case 2: return '*';
        case -2: return '/';
    }
}
int main(){
    string s;
    string ans="";
    stack<int>st;
    cout<<"Enter Infix Experssion:"<<endl;
    getline(cin,s);
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(0);
        }
        else if(s[i]==')'){
            while(st.top()!=0){
                int t=st.top();
                st.pop();
                char ch=oper(t);
                ans+=ch;
            }
            st.pop();
        }
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
            ans+=s[i];
        }
        else{
            if(st.empty()||st.top()==0){
                st.push(pres(s[i]));
            }else{
            while(!st.empty() && st.top()>=abs(pres(s[i]) && st.top()!=0)){
                int t=st.top();
                st.pop();
                //we need to get that opertor..
                char ch=oper(t);
                ans+=ch;
            }
            st.push(pres(s[i]));
            }
        }
    }
    while(!st.empty()){
        int t=st.top();
        st.pop();
        char ch=oper(t);
        ans+=ch;
    }
    cout<<"Postfix expression:"<<endl;
    cout<<ans<<endl;
}