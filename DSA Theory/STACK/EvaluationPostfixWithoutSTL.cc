#include<iostream>
#include<stack>
using namespace std;
void push(int val,int *top,int st[],int n){
        st[++(*top)]=val;
}
int pop(int st[],int *top){
    int k=st[*top];
    (*top)--;
    return k;
}
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
    int i=0,n=s.length();
    int top=-1;
    int st[n];
    while(i<n){
        if(s[i]>='0' && s[i]<='9'){
            push(s[i]-'0',&top,st,n);
        }else{
            int b=pop(st,&top);
            int a=pop(st,&top);
            int res=eval(a,b,s[i]);
            push(res,&top,st,n);
        }
        i++;
    }
    int finalres=pop(st,&top);
    cout<<"Result is:"<<finalres<<endl;
    return 0;
}