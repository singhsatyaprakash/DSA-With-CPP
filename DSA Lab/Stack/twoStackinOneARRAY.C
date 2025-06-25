/*
Problem Statement II. Design an algorithm and a program to implement two stacks by using only one array i.e. both the
stacks should use the same array for push and pop operation. Array should be divided in such a
manner that space should be efficiently used if one stack contains very large number of elements
and other one contains only few elements.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#define n 10
void push1(int stack[],int *top,int *centre,int val){
    if(*top==*centre){
        printf("Stack is full.");
    }else{
        stack[++(*top)]=val;
    }
}
int pop1(int stack[],int *top){
    if(*top==-1){
        printf("Called Stack is empty.");
        return -1;
    }
    int k=stack[*top];
    (*top)--;
    return k;
}
void push2(int stack[],int *top,int *centre,int val){
    if(*top==*centre){
        printf("Stack is full.");
    }else{
        stack[--(*top)]=val;
    }
}
int pop2(int stack[],int *top){
    if(*top==n){
        printf("Called Stack is empty.");
        return -1;
    }
    int k=stack[*top];
    (*top)++;
    return k;
}
void display1(int arr[],int front){
    for(int i=front;i>=0;i--){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void display2(int arr[],int rear){
    for(int i=rear;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[n];
    int choice;
    int front=-1,rear=n;
    printf("Press[1] to push in Stack 1\n");
    printf("Press[2] to pop from Stack 1\n");
    printf("Press[3] to push in Stack 2\n");
    printf("Press[4] to pop from Stack 2\n");
    printf("Press[5] to print Stack 1\n");
    printf("Press[6] to print Stack 2\n");
    printf("Press[0] to exit\n");
    do{
        printf("Enter:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int val;
                printf("Value to push:");
                scanf("%d",&val);
                push1(arr,&front,&rear,val);
                break;
            }
            case 2:{
                int k=pop1(arr,&front);
                printf("Popped:%d\n",k);
                break;
            }
            case 3:{
                int val;
                printf("Value to push:");
                scanf("%d",&val); 
                push2(arr,&rear,&front,val);
                break;
            }
            case 4:{
                int k=pop2(arr,&rear);
                printf("Popped:%d\n",k);
                break;
            }
            case 5:{
                printf("Stack 1:");
                display1(arr,front);
                break;
            }
            case 6:{
                printf("Stack 2:");
                display2(arr,rear);
                break;
            }
            default:
            printf("Invalid Option\n");
        }

    }while(choice!=0);
}
