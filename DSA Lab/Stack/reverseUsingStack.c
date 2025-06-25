/*
Problem Statement I. Given an empty stack, design an algorithm and a program to reverse a string using this stack
(with and without recursion).
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<string.h>
#define n 50
void push(char ch,char stack[],int *top){
    if(*top==n-1){
        printf("Stack is full.");
    }else{
        stack[++(*top)]=ch;
    }
}
char pop(char stack[],int *top){
    char ch=stack[*top];
    (*top)--;
    return ch;
}
int main(){
    char str[n];
    printf("Enter String:");
    gets(str);
    char stack[n];
    int top=-1;
    for(int i=0;i<strlen(str);i++){
        push(str[i],stack,&top);
    }
    for(int i=0;top!=-1;i++){
        char ch=pop(stack,&top);
        str[i]=ch;
    }
    printf("Reverse string is:%s",str);
    return 0;
}
