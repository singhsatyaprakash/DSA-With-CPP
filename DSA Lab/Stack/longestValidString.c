/*
Problem Statement III.Given a string of opening and closing paranthesis, design an algorithm and a program to find the
length of the longest valid paranthesis substring. Valid paranthesis substring is a string which
contains balanced paranthesis.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/

#include<stdio.h>
#include<string.h>
int main(){
    char str[50];
    printf("Enter string:");
    scanf("%[^\n]s",str);
    int n=strlen(str);
    int arr[n+1];//Creating stack
    int top=-1;
    arr[++top]=-1;//to handle edge case
    int maxLength=0,count=0;
    for(int i=0;i<n;i++){
        if(str[i]=='('){
            arr[++top]=i;//push index
        }
        else{
            if(top>=0){
                top--;//pop
            }
            if(top<0){//edge case )))
            arr[++top]=i;//push index
            }
            else{
                //updating length...
                count=i-arr[top];
                if(count>maxLength){
                    maxLength=count;
                }
            }
        }
    }
    printf("Maximum valid length of string is:%d",maxLength);
    return 0;
}