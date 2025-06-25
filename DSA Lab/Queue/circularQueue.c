/*
Problem Statement 18:Design an algorithm and write a program to implement circular queue. Circular queue is a
queue in which last position of queue is connected with first position of queue to make a circle.
The program should implement following operations:
a) Create() - create a queue of specific size
b) EnQueue(k) - insert an element k into the queue
c) DeQueue() - delete an element from the queue
d) IsEmpty() - check if queue is empty or not
e) Front() - return front item from queue
f) Rear() - return rear item from queue
Name:Satya Prakash Singh
Section:A1
Roll No:61
Course:B.Tech(CSE)
*/
#include <stdio.h>
#include<stdbool.h>
int IsEmpty(int front){
    return (front==-1);
}
int IsFull(int front,int rear,int n){
    if((rear + 1)%n == front){
        return true;
    }
    else{
        return false;
    }
}
//insert..
void EnQueue(int* queue,int* front,int* rear,int n,int value){
    if(IsFull(*front,*rear,n)){
        printf("Queue is full\n");
        return;
    }
    if(IsEmpty(*front)){
        *front=0;
    }
    *rear=(*rear + 1)%n;
    queue[*rear]=value;
}
//deleting..
int DeQueue(int* queue,int* front,int* rear,int n){
    if(IsEmpty(*front)){
        printf("Queue is empty\n");
        return -1;
    }
    int k=queue[*front];
    if(*front==*rear){ //Only one element in queue then delete and reintialise front and rear..
        *front=-1;
        *rear=-1;
    }
    else{
        *front=(*front+1)%n;
    }
    return k;
}
int Front(int* queue,int front){
    if(IsEmpty(front)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}
int Rear(int* queue,int rear){
    if(rear==-1){
        printf("Queue is empty\n");
        return -1;
    }
    return queue[rear];
}
void Display(int* queue,int front,int rear,int n){
    if(IsEmpty(front)){
        printf("Queue is empty\n");
        return;
    }
    printf("Circular Queue: ");
    int i=front;
    while(1){
        printf("%d ",queue[i]);
        if(i==rear){
            break;
        }
        i=(i+1)%n;
    }
    printf("\n");
}
int main(){
    int n,choice,value;
    int front=-1,rear=-1;
    printf("Enter size of the circular queue: ");
    scanf("%d",&n);
    int queue[n];
    printf("Menu:\n");
    printf("Press [1] to EnQueue an element\n");
    printf("Press [2] to DeQueue an element\n");
    printf("Press [3] to check if queue is empty\n");
    printf("Press [4] to get the front item\n");
    printf("Press [5] to get the rear item\n");
    printf("Press [6] to Display Circular Queue\n");
    printf("Press [0] to Exit.\n");
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter element to enqueue: ");
                scanf("%d",&value);
                EnQueue(queue,&front,&rear,n,value);
                break;
            }
            case 2:{
                value=DeQueue(queue,&front,&rear,n);
                if(value!=-1){
                    printf("Dequeued element: %d\n",value);
                }
                break;
            }
            case 3:{
                if(IsEmpty(front)){
                    printf("Queue is empty\n");
                }
                else{
                    printf("Queue is not empty\n");
                }
                break;
            }
            case 4:{
                value=Front(queue,front);
                if(value!=-1){
                    printf("Front element:%d\n",value);
                }
                break;
            }
           case 5:{
                value=Rear(queue,rear);
                if(value!=-1){
                    printf("Rear element:%d\n",value);
                }
                break;
            }
           case 6:{
                Display(queue,front,rear,n);
                break;
            }
            case 0:{
                printf("Exit.\n");
                break;
            }
            default:
                printf("Invalid Choice!\n");
        }
    }while(choice!=0);
    return 0;
}
