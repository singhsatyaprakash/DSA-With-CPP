/*
15. Design an algorithm and write a program to implement Deque i.e. double ended queue. Double
ended queue is a queue in which insertion and deletion can be done from both ends of the queue.
The program should implement following operations:
a) insertFront() - insert an element at the front of Deque
b) insertEnd() - insert an element at the end of Deque
c) deleteFront() - delete an element from the front of Deque
d) deleteEnd() - delete an element from the end of Deque
e) isEmpty() - checks whether Deque is empty or not
f) isFull() - checks whether Deque is full or not
g) printFront() - print Deque from front
h) printEnd() - print Deque from end

Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
void isEmpty(int* front,int* rear,int n){
    if(*front==-1 && *rear==-1){
        printf("Queue is Empty.\n");
    }
    else{
        printf("Queue is not Empty.\n");
    }
}
void isFull(int* front,int* rear,int n){
    if((*front==0 && *rear ==n-1)|| *front==*rear + 1){
        printf("Queue is full.\n");
    }
    else{
        printf("Queue is not full.\n");
    }
}
void EnqueueRear(int queue[],int *front,int *rear,int n,int val){
    if((*front==0 && *rear ==n-1)|| *front==*rear + 1){
        printf("Queue is full.\n");
        return;
    }
    else if(*front==-1 && *rear==-1){//first insert element
    ++(*front);
    ++(*rear);
    queue[*rear]=val;
    }
    else if(*rear==n-1 && *front!=0){
        *rear=0;
        queue[*rear]=val;
    }
    else{
        ++(*rear);
        queue[*rear]=val;
    }
}
void EnqueueFront(int queue[],int *front,int *rear,int n,int val){
    if((*front==-1 && *rear==n-1)|| *front==*rear+1){
        printf("Queue is Full.\n");
        return;
    }
    else if(*front==-1 && *rear==-1){//first element insert..
        ++(*front);
        ++(*rear);
        queue[*front]=val;
    }
    else if(*front==0){
            *front=n-1;
            queue[*front]=val;
    }
    else{
        --(*front);
        queue[*front]=val;
    }
}
void DisplayFrontToRear(int queue[],int front,int rear,int n){
    printf("QueueFrontToRear:");
    if(front<=rear){
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
    else{
        for(int i=front;i<=n-1;i++){
            printf("%d ",queue[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
}
void DisplayRearToFront(int queue[], int front, int rear, int n) {
    printf("QueueRearToFront: ");
    if(front==-1 && rear==-1){
        printf("Queue is empty.\n");
        return;
    }
    if(front<=rear){
        // If the front is before the rear in the array (no wrap around)
        for(int i=rear;i>=front;i--){
            printf("%d ",queue[i]);
        }
    }
    else{
        // If the rear is before the front due to wrap around
        for(int i=rear;i>=0;i--){
            printf("%d ",queue[i]);
        }
        for(int i=n-1;i>=front;i--){
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
}

int DequeueFront(int queue[],int *front,int *rear,int n){
    int k;
    if(*front==-1 && *rear==-1){
        printf("Queue is Empty.\n");
        return -1;
    }
    else if(*front==*rear){//one element remains in queue..
        k=queue[*front];
        *front=*rear=-1;
    }
    else if(*front==n-1){
        k=queue[*front];
        *front=0;
    }
    else{//general case..
        k=queue[*front];
        (*front)++;
    }
    return k;
}
int DequeueRear(int queue[],int *front,int *rear,int n){
        int k;
    if(*front==-1 && *rear==-1){
        printf("Queue is Empty.\n");
        return -1;
    }
    else if(*front==*rear){//one element remains in queue..
        k=queue[*front];
        *front=*rear=-1;
    }
    else if(*rear==0){
        k=queue[*rear];
        *rear=n-1;
    }
    else{
        k=queue[*rear];
        (*rear)--;
    }
    return k;
}
int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int queue[n];
    int front=-1,rear=-1;
    printf("Press[1] for Enqueue Rear\n");
    printf("Press[2] for Enqueue Front\n");
    printf("Press[3] for Dequeue Rear\n");
    printf("Press[4] for Dequeue Front\n");
    printf("Press[5] for Isempty\n");
    printf("Press[6] for IsFull\n");
    printf("Press[7] for Display FrontToRear\n");
    printf("Press[8] for Display RearToFront\n");
    printf("Press[0] to Exit.\n");
    int choice;
    int exit;
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int val;
                printf("Enter element to EnqueueRear:");
                scanf("%d",&val);
                EnqueueRear(queue,&front,&rear,n,val);
                break;
            }
            case 2:{
                int val;
                printf("Enter element to EnqueueFront:");
                scanf("%d",&val);
                EnqueueFront(queue,&front,&rear,n,val);
                break;
            }
            case 3:{
                int k=DequeueRear(queue,&front,&rear,n);
                printf("Dequeue element is:%d\n",k);
                break;
            }
            case 4:{
                int k=DequeueFront(queue,&front,&rear,n);
                printf("Dequeue element is:%d\n",k);
                break;
            }
            case 5:{
                isEmpty(&front,&rear,n);
                break;
            }
            case 6:{
                isFull(&front,&rear,n);
                break;
            }
            case 7:{
                DisplayFrontToRear(queue,front,rear,n);
                break;
            }
            case 8:{
                DisplayRearToFront(queue,front,rear,n);
                break;
            }
            case 0:{
                printf("Exit.\n");
            }
            default:
            printf("Invalid Choice.\n");
        }
    }while(choice!=0);
}