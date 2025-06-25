/*
Problem Statement III. Given an expression in the form of postfix representation, design an algorithm and a program to
find result of this expression.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter string:");
    gets(str);
    char* token;
    token=strtok(str,' ');
    while(token){
        token=strtok(NULL,' ');
    }
    char stack[100];
    int top=-1;
    for(int i=0;i<strlen(str);i++){
        printf("%s",token[i]);
        
    }
}