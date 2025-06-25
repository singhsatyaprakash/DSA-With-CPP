/*
Problem Statement 17:Design an algorithm and write a program to implement queue operations using minimum
number of stacks.
Name:Satya Prakash Singh
Section:A1
Roll No:61
Course:B.Tech(CSE)
*/
#include <stdio.h>
void push(int stack[],int *top, int value, int n){
    if(*top==n-1){
        printf("Stack is full\n");
        return;
    }
    stack[++(*top)]=value;
}

int pop(int stack[],int *top){
    if(*top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[(*top)--];
}
void enqueue(int s1[],int *top1,int s2[],int *top2,int value,int n){
    push(s1,top1,value,n);
}

int dequeue(int s1[],int *top1,int s2[],int *top2,int n){
    if(*top2==-1){//If s2 is empty
        if(*top1==-1){// If s1 is also empty
            printf("Queue is empty\n");
            return -1;
        }
        // Transfer all elements from s1 to s2
        while(*top1!=-1){
            int temp=pop(s1,top1);
            push(s2,top2,temp,n);
        }
    }
    return pop(s2,top2);
}
void display(int s1[],int top1,int s2[],int top2){
    if(top1==-1 && top2==-1){
        printf("Queue is empty\n");
        return;
    }
    // Display elements of s2 in reverse (front to back of queue)
    for(int i=top2;i>=0;i--){
        printf("%d ",s2[i]);
    }
    // Display elements of s1 (back to front of queue)
    for(int i=0;i<=top1;i++){
        printf("%d  ",s1[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter size of queue: ");
    scanf("%d",&n);
    int s1[n],s2[n];
    int top1=-1,top2=-1;
    printf("Press [1] to enqueue an element\n");
    printf("Press [2] to dequeue an element\n");
    printf("Press [3] to display\n");
    printf("Press [0] to Exit.\n");
    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int val;
                printf("Enter element to enqueue: ");
                scanf("%d",&val);
                enqueue(s1,&top1,s2,&top2,val,n);
                break;
            }
            case 2: {
                int k=dequeue(s1,&top1,s2,&top2,n);
                if(k!=-1){
                    printf("Dequeued Element: %d\n",k);
                }
                printf("Queue after dequeue: ");
                display(s1,top1,s2,top2);
                break;
            }
            case 3: {
                printf("Queue: ");
                display(s1,top1,s2,top2);
                break;
            }
            case 0:{
                printf("Exit.\n");
                break;
            }
            default:
                printf("Invalid Choice!!!\n");
        }
    }while(choice!=0);
    return 0;
}
