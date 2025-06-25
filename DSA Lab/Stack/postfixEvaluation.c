/*
12. Given an expression in the form of postfix representation, design an algorithm and a
program to find result of this expression.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
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
        case '^': return pow(a,b);
    }
}
int main(){
    char s[100];
    printf("Enter expression:");
    gets(s);
    int i=0,n=strlen(s);
    int top=-1;
    int st[n];
      while(i<n){
        if(isdigit(s[i])){
            //Handle multi-digit numbers
            int num=0;
            while(i<n && isdigit(s[i])){//jab tak digit hai..
                num=num*10+(s[i]-'0');//string to integer..
                i++;
            }
            push(num,&top,st,n);
        }
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^'){
            int b=pop(st,&top);
            int a=pop(st,&top);
            int res=eval(a,b,s[i]);
            push(res,&top,st,n);
            i++;
        }
        else{ // Skip spaces
            i++;
        }
    }
    int finalres=pop(st,&top);
    printf("Result is:%d",finalres);
    return 0;
}
