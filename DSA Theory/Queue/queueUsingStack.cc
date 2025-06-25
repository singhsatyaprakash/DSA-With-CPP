//enqueue costly dequeue optimal...
#include<iostream>
using namespace std;
#define n 5
void display(int s1[],int top1){
    for(int i=top1;i>=0;i--){
        cout<<s1[i]<<" ";
    }
    cout<<endl;
}
int pop(int s[],int* top){
    int poped;
    if(*top==-1){
        return -1;
    }
    else{
    poped=s[*top];
    (*top)--;
    }
    return poped;
}
void push(int s[],int* top,int x){
    if(*top==n-1){
        cout<<"Stack is full"<<endl;
    }
    else{
        ++(*top);
        s[*top]=x;
    }
}
bool isEmpty(int s1[],int* top1){
    if(*top1==-1){
        return true;
    }
    else{
        return false;
    }
}
int dequeue(int s1[],int* top1){
    int x;
    if((*top1==-1)){
        cout<<"Queue is empty"<<endl;
    }
    else{
    x=s1[*top1];
    (*top1)--;
    }
    return x;
}
void enqueue(int s1[],int s2[],int *top1,int *top2,int x){
    if(*top1==n-1){
        cout<<"Queue is full"<<endl;
    }
    else{
    while(!isEmpty(s1,top1)){//*top1!=-1
        int t=pop(s1,top1);
        push(s2,top2,t);
    }
    push(s1,top1,x);
    while(!isEmpty(s2,top2)){
        int t=pop(s2,top2);
        push(s1,top1,t);
    }
    }
}
int main(){
    int s1[n];
    int s2[n];
    int top1=-1,top2=-1;
    enqueue(s1,s2,&top1,&top2,14);
    enqueue(s1,s2,&top1,&top2,10);
    enqueue(s1,s2,&top1,&top2,11);
    display(s1,top1);
    dequeue(s1,&top1);
    display(s1,top1);
    enqueue(s1,s2,&top1,&top2,-1);
    display(s1,top1);
    dequeue(s1,&top1);
    display(s1,top1);    
    enqueue(s1,s2,&top1,&top2,2);
    display(s1,top1);
    return 0;
}