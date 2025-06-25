/*
Problem Statement II. Given an expression string consisting of opening and closing brackets “{“,”}”,”(“,”)”,”[“,”]”,
design an algorithm and a program to check whether this expression has balanced paranthesis or
not.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
void push(char arr[],char ch,int* top){
    arr[++(*top)]=ch;
    return;
}
void pop(char arr[], int *top){
    (*top)--;
    return;
}
bool isStackEmpty(int top){
    if(top==-1){
        return true;//stack is empty..
    }
    else{
        return false;//stack is not empty..
    }
}
int getcode(char ch){
    if(ch=='('){
        return 1;
    }
    else if(ch=='{'){
        return 2;
    }
    else if(ch=='['){
        return 3;
    }
    else if(ch==')'){
        return -1;
    }
    else if(ch=='}'){
        return -2;
    }
    else if(ch==']'){
        return -3;
    }
    return 0;
}

int main(){

 char s[50];
 printf("Enter string: ");
 fflush(stdin);
 scanf("%[^\n]s",s);
 int n=strlen(s);
 char arr[n];
 int top=-1;
 int flag=0,code1=0,code2=0;
 for(int i=0;i<n;i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push(arr,s[i],&top);
        }
        else if(!isStackEmpty(top)&&(s[i]==')'||s[i]=='}'||s[i]==']')){
            code1=getcode(arr[top]);
            code2=getcode(s[i]);
            if(abs(code1+code2)==0){
                pop(arr,&top);
            }
       }
       else{
       printf("Not Balacned");
       flag=1;
       break;
       }
 }
       if(!flag){
       		if(isStackEmpty(top)){
       		printf("Balanced");
       		}
       		else{
       		printf("Not Balanced");
       		}
       }
 return 0;
 }