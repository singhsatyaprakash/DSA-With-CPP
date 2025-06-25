/*
Problem Statement 21:Write an algorithm and a program to implement stack using linked list. he program should
implement following queue operations:
a) Create()
b) Push()
c) Pop()
d) IsEmpty()
e) IsFull()
f) Size()
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    struct node* top;
    int size; //size of stack..
}stack;

//function to create stack..
stack* CreateStack(){
    stack* s=(stack*)malloc(sizeof(stack));
    if(s==NULL){
        printf("Stack Not created.\n");
    } 
    else{
    s->top=NULL;
    s->size=0;
    printf("Stack created.\n");
    }
    return s;
}
//function to create newnode..
node* CreateNode(int val){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("Node not created.\n");
    }
    else{
    newnode->data=val;
    newnode->next=NULL;
    }
    return newnode;
}
//push into stack..
void Push(stack* s,int val){
    node* newnode=CreateNode(val);
    if(newnode==NULL){ 
        return;
    }
    newnode->next=s->top;
    s->top=newnode;
    s->size++;
}

//pop from stack...
int Pop(stack* s){
    if(s->top==NULL){
        printf("Stack is empty.\n");
        return -1;
    }
    node* temp=s->top;
    int k=temp->data;
    s->top=s->top->next;
    free(temp);
    s->size--;
    printf("Popped element is:%d\n",k);
    return k;
}
int IsEmpty(stack* s){
    return (s->top==NULL);
}
int Size(stack* s){
    return s->size;
}
void Display(stack* s){
    if(IsEmpty(s)){
        printf("Stack is empty.\n");
        return;
    }
    node* temp=s->top;
    printf("Stack: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    stack* s;
    int choice,val;
    printf("Press[1] for Create Stack\n");
    printf("Press[2] for Push\n");
    printf("Press[3] for Pop\n");
    printf("Press[4] for IsStackEmpty\n");
    printf("Press[5] for StackSize\n");
    printf("Press[6] for DisplayStack\n");
    printf("Press[0] for Exit\n");
    do{
        printf("Choice:");
        scanf("%d",&choice);        
        switch(choice){
            case 1:
                s=CreateStack();
                break;
            case 2:
                printf("Enter value to push:");
                scanf("%d",&val);
                Push(s,val);
                break;
            case 3:
                Pop(s);
                break;
            case 4:
                if(IsEmpty(s)){
                    printf("Stack is empty.\n");
                }
                else{
                    printf("Stack is not empty.\n");
                }
                break;
            case 5:
                printf("Stack size: %d\n", Size(s));
                break;
            case 6:
                Display(s);
                break;
            case 0:
                printf("Exit.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice!=0);
    return 0;
}
