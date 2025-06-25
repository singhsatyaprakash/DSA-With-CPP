/*
Problem Statement 20:Write an algorithm and a program to implement queue using linked list. The program should
implement following stack operations:
a) Create()
b) EnQueue()
c) DeQueue()
d) IsEmpty()
e) Size()
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
typedef struct queue{
    struct node* front;
    struct node* rear;
}queue;

queue* CreateQueue(){
    queue *ptr=(queue*)malloc(sizeof(queue));
        if(ptr==NULL){
        printf("queue not create.\n");
    }
    else{
        printf("Queue Created.\n");
    }
    ptr->front=NULL;
    ptr->rear=NULL;
    return ptr;
}

node* CreateNode(int val){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("Node not create.\n");
    }
    else{
        printf("Node Created.\n");
    }
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
void Enqueue(queue *q,int val){
    node* newnode=CreateNode(val);
    if(q->front==NULL){
        q->front=newnode;
        q->rear=newnode;
    }
    else{
        (q->rear)->next=newnode;
        q->rear=newnode;
    }
}
void Dequeue(queue *q){
    if(q->front==NULL){
        printf("Queue is Empty.\n");
        return;
    }
    else{
        node* del=q->front;
        q->front=(q->front)->next;
        printf("Dequeue Element is:%d\n",del->data);
        free(del);
    }
}
void IsEmpty(queue* q){
    if((q->front)==NULL){
        printf("Queue is Empty.\n");
    }
    else{
        printf("Queue is not Empty.\n");
    }
}
int FindSize(queue* q){
    int count=0;
    queue* temp=q;
    while(temp->front!=NULL){
        count++;
        temp->front=(temp->front)->next;
    }
    return count;
}
void DisplayList(queue* q){
    node* temp=q->front; // Use a temporary pointer to traverse the queue
    printf("Queue: ");
    while(temp!=NULL){
        printf("%d --> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    queue* q;
    int choice,k;
    printf("Press[1] to CreateQueue\n");
    printf("Press[2] to Enqueue\n");
    printf("Press[3] to Dequeue\n");
    printf("Press[4] to IsEmpty\n");
    printf("Press[5] to Size\n");
    printf("Press[6] to Display\n");
    printf("Press[0] to Exit.\n");
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                q=CreateQueue();
                break;
            }
            case 2:{
                printf("Enter value to enqueue:");
                scanf("%d",&k);
                Enqueue(q,k);
                break;
            }
            case 3:{
                Dequeue(q);
                break;
            }
            case 4:{
                IsEmpty(q);
                break;
            }
            case 5:{
                printf("Size of queue is:%d\n",FindSize(q));
                break;
            }
            case 6:{
                DisplayList(q);
                break;
            }
            case 0:{
                printf("Exit.\n");
                break;
            }
            default:
            printf("Invalid Choice.\n");
        }
    }while(choice!=0);
    return 0;
}
