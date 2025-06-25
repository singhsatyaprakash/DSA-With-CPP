/*
13. Design an algorithm and a program to implement queue using array. The program should
implement following queue operations:
1. a) Create() - create a queue
2. b) EnQueue(k) - insert an element k into the queue
3. c) DeQueue() - delete an element from the queue
4. d) IsEmpty() - check if queue is empty or not
5. e) Size() - finds the size of the queue

Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#define n 5
void isEmpty(int q[],int* front){
    if(*front==-1){
        printf("Queue is empty\n");
    }else{
        printf("Queue is not empty\n");
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
int main(){
    int front=-1,rear=-1;
    int q[n];
    int choice;
    printf("Press[1] for Enqueue\n");
    printf("Press[2] for Dequeue\n");
    printf("Press[3] for IsEmpty\n");
    printf("Press[4] for SizeOfQueue\n");
    printf("Press[5] for Display Queue\n");
    printf("Press[0] for Exit\n");
    do{
        printf("Enter:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int val;
                printf("Enter val to push:");
                scanf("%d",&val);
                Enqueue(q,&front,&rear,val);
                break;
            }
            case 2:{
                int k=Dequeue(q,&front,&rear);
                if(k!=-1){
                printf("Dequeue element is:%d\n",k);
                }else{
                    printf("Queue is empty\n");
                }
                break;
            }
            case 3:{
                isEmpty(q,&front);
                break;
            }
            case 4:{
                printf("Size of Queue is:%d\n",rear+1);
                break;
            }
            case 5:{
                display(q,front,rear);
            }
        }
    }while(choice!=0);
    return 0;
}