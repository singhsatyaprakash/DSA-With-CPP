//enqueue costly dequeue optimal...
#include<iostream>
using namespace std;
#define n 5

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
bool isEmpty(int s[],int* top){
    if(*top==-1){
        return true;
    }
    else{
        return false;
    }
}
int dequeue(int s1[],int s2[],int* top1,int* top2){
    int x=-1;
    if(isEmpty(s1,top1) && isEmpty(s2,top2)){ //both empty..
        cout<<"Queue is empty"<<endl;
    }
    else{
        if(!isEmpty(s2,top2)){//s2 is not empty
        x=pop(s2,top2);
        }
        else{
            while(!isEmpty(s1,top1)){//s1 is not empty
                push(s2,top2,pop(s1,top1));
            }
            x=pop(s2,top2);
        }
    }
    return x;
}
void enqueue(int s1[],int* top1,int x){
    if(*top1==n-1){
        cout<<"Queue is full"<<endl;
    }
    else{
        push(s1,top1,x);
    }
}
void display(int s1[],int s2[],int *top1,int *top2){
    while(!isEmpty(s2,top2)){//s2 is not empty
       push(s1,top1,pop(s2,top2));
    }
    for(int i=0;i<=(*top1);i++){
        cout<<s1[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int s1[n];
    int s2[n];
    int top1=-1,top2=-1;
    enqueue(s1,&top1,10);
    enqueue(s1,&top1,15);
    enqueue(s1,&top1,19);
    display(s1,s2,&top1,&top2);
    cout<<"Deleted element is:"<<dequeue(s1,s2,&top1,&top2)<<endl;
    display(s1,s2,&top1,&top2);
    cout<<"Deleted element is:"<<dequeue(s1,s2,&top1,&top2)<<endl;
    display(s1,s2,&top1,&top2);
    enqueue(s1,&top1,21);
    enqueue(s1,&top1,100);
    cout<<"Deleted element is:"<<dequeue(s1,s2,&top1,&top2)<<endl;
    display(s1,s2,&top1,&top2);
    return 0;
}