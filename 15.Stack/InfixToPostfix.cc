#include<iostream>
#include<string>
using namespace std;
bool isStackEmpty(int *top){
    if(*top==-1){
        return true;//stack is empty..
    }
    else{
        return false;//stack not empty..
    }
}
void push(char arr[],char ch,int *top){
    arr[++(*top)]=ch;
    return;
}
void pop(char arr[],int *top){
    (*top)--;
}
//return top element of stack
char topEle(char st[],int *top){
    return st[(*top)];
}
int pres(char c) {
    switch(c) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        default: return 0;
    }
}
int main(){
    string s;
    string ans = "";
    cout<<"Enter Infix Expression:"<<endl;
    getline(cin,s);
    int n=s.length();
    char st[n];//creating stack
    int top=-1;
    for(int i=0;i<n;i++){
        char ch=s[i];
        //if incomin charcater is an operand ,output it..ans
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            ans+=ch;
        }
        else if(ch=='('){
            push(st,ch,&top);
        }
        else if(ch==')'){
            while(!isStackEmpty(&top) && topEle(st,&top)!='('){
                ans+=topEle(st,&top);
                pop(st,&top);
            }
            pop(st,&top); //remove '('
        }
        else {
            while(!isStackEmpty(&top) && pres(topEle(st,&top))>=pres(ch)){
                ans+=topEle(st,&top);
                pop(st,&top);
            }
            push(st,ch,&top);
        }
    }
    //pop all...
    while(!isStackEmpty(&top)){
        ans+=topEle(st,&top);
        pop(st,&top);
    }
    cout<<"Postfix expression:"<<endl;
    cout<<ans<<endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and add to the output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); 
        }

        // If an operator is scanned
        else {
            while (!st.empty() && prec(c) < prec(st.top()) ||
                   !st.empty() && prec(c) == prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
*/