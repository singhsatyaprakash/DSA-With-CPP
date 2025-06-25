#include<stdio.h>
#include<string.h>
#define m 50
void push(char stack[],int *top,char str[],int n,int i){
    if(i==n-1){
        return;
    }
    (*top)++;
    stack[*top]=str[i];
    i++;
    push(stack,top,str,n,i);
}
void pop(char stack[],int *top,char str[],int i){
    if(*top==-1){
        return;
    }
    char ch=stack[*top];
    (*top)--;
    str[i]=ch;
    i++;
    pop(stack,top,str,i);
}
int main(){
    int str[m];
    printf("Enter string:");
    gets(str);
    int top=-1;
    char stack[m];
    push(stack,&top,str,strlen(str),0);
    pop(stack,&top,str,0);
    printf("Reverse string is:%s",str);
    return 0;
}