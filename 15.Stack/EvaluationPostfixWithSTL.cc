#include<iostream>
#include<stack>
using namespace std;
int eval(int a,int b,char ch){
    switch(ch){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
}
int main(){
    string s;
    cout<<"Enter expression:"<<endl;
    getline(cin,s);
    stack<int>st;
    int i=0,n=s.length();
    while(i<n){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            int res=eval(a,b,s[i]);
            st.push(res);
        }
        i++;
    }
    cout<<"Result is:"<<st.top()<<endl;
    return 0;
}