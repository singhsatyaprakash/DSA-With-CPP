/*
Problem Statement 14.Design an algorithm and write a program to reverse a queue.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/

//reverse queue using stack
#include<stdio.h>
#include<stdbool.h>
#define n 5
bool isEmpty(int q[],int* front){
    if(*front==-1){
        return true;
    }else{
        return false;
    }
}
int Dequeue(int q[],int* front,int* rear){
    int k=-1;//return -1 is nothing to dequeue...
    if(*front==-1){
        *front=*rear=-1;
    }else{
        k=q[*front];
        (*front)++;
        if(*rear<*front){//reinitalize queue to original state...
            *rear=*front=-1;
        }
    }
    return k;
}
void Enqueue(int q[],int* front,int *rear,int val){
    if((*rear)==n-1){
        printf("Queue is Full.\n");
        return;
    }else{
        if(*front==-1){
            ++(*front);
        }
        q[++(*rear)]=val;
    }
}
void display(int q[],int front,int rear){
    if(front==-1){
        printf("Queue is empty.\n");
        return;
    }
    else{
        printf("Queue:");
        for(int i=front;i<=rear;i++){
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}
//resversing queue using recursion...
void reverse(int q[],int *front,int *rear){
    int val;
    if(isEmpty(q,front)){
        return;
    }
    val=Dequeue(q,front,rear);
    reverse(q,front,rear);
    Enqueue(q,front,rear,val);
}
int main(){
    int front=-1,rear=-1;
    int q[n];
    int choice;
    printf("Press[1] for Enqueue\n");
    printf("Press[2] for Display Queue\n");
    printf("Press[3] to reverse queue\n");
    printf("Press[0] for Exit\n");
    do{
        printf("Enter:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int val;
                printf("Enter val to enqueue:");
                scanf("%d",&val);
                Enqueue(q,&front,&rear,val);
                break;
            }
            case 2:{
                display(q,front,rear);
                break;
            }
            case 3:{
                reverse(q,&front,&rear);
                printf("Queue is reversed.\n");
                break;
            }
        }
    }while(choice!=0);
    return 0;
}