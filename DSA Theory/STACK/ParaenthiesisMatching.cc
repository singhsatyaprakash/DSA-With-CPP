/*
Question:Write a program to implement Parentheses matching algorithm having the following brackets (),{},[].The string to be enter by the user.
*/
#include<iostream>
#include<string>
using namespace std;
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
}

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


int main(){
    int n,code1=0,code2=0;
    int flag=0;
    string str;
    cout<<"Enter the string:"<<endl;
    getline(cin,str);
    n=str.length();
    char arr[n];//creating stack..
    int top=-1;//showing stack is empty..
    for(int i=0;i<n;i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            push(arr,str[i],&top);
        }
        else if((!(isStackEmpty(&top)))&&(str[i]==')'||str[i]=='}'||str[i]==']')){
            code1=getcode(arr[top]);
            code2=getcode(str[i]);
            if(abs(code1+code2)==0){
                pop(arr,&top);
            } 
        }
        else{
            cout<<"NOT MATCHED..."<<endl;
            flag=1;
            break;
        }
    }

    if(flag==0){
        if(isStackEmpty(&top)){
            cout<<"Brackets Matched.."<<endl;
        }
        else{
            cout<<"NOT MATCHED..."<<endl;
        }
    }
    return 0;
}