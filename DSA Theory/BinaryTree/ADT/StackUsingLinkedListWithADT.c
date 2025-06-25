#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Node{
    int data;
    struct Node* next;
}node;
typedef struct Stack{
    node* top;
}stack;
void initilaise_Stack(stack* st){
    st->top=NULL;
}
node* CreateNode(int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void push(stack* st,int data){
    node* newnode=CreateNode(data);
    if(!newnode){
        printf("Not sufficient Memory.\n");
    }
    else{
        newnode->next=st->top;
        st->top=newnode;//push at top is insert at front..
    }
}
int pop(stack* st){
    if(st->top==NULL){
        printf("Stack is Empty.\n");
        return INT_MIN;
    }
    int k=(st->top)->data;
    node* del=st->top;
    st->top=(st->top)->next;
    del->next=NULL;
    free(del);
    return k;
}
void display(stack* st){
    printf("Stack:");
    node* temp=st->top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    stack* st;
    initilaise_Stack(st);
    push(st,10);
    push(st,20);
    push(st,30);
    display(st);
    printf("Pop element:%d\n",pop(st));
    printf("Pop element:%d\n",pop(st));
    push(st,51);
    display(st);
    return 0;
}