#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Stack{
    int top;
    int capacity;
    int *array;
}stack;
stack* CreateStack(int cap){
    //initilaise stack...
    stack* st=(stack*)malloc(sizeof(stack));
    st->capacity=cap;
    st->top=-1;
    st->array=(int*)malloc(sizeof(int)*st->capacity);
    return st;
}
void push(stack* st,int data){
    if(st->top>=st->capacity-1){
        printf("Stack is full.\n");
    }
    else{
        st->array[++(st->top)]=data;
    }
}
int pop(stack* st){
    if(st->top==-1){
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    int k=st->array[(st->top)--];
    return k;
}
void display(stack *st){
    int temp=st->top;
    for(int i=temp;i>=0;i--){
        printf("%d ",st->array[i]);
    }
    printf("\n");
}
int main(){
    stack *st=CreateStack(5);//with parameter capacity..
    push(st,10);
    push(st,20);
    push(st,30);
    push(st,40);
    push(st,50);
    printf("Stack: ");
    display(st);
    push(st,60);//full stack..
    printf("Pop element:%d\n",pop(st));
    printf("Stack: ");
    display(st);
    push(st,100);
    printf("Stack: ");
    display(st);
    printf("Pop element:%d\n",pop(st));
    printf("Pop element:%d\n",pop(st));
    printf("Pop element:%d\n",pop(st));
    printf("Stack: ");
    display(st);
    printf("Pop element:%d\n",pop(st));
    printf("Pop element:%d\n",pop(st));
    printf("Pop element:%d\n",pop(st));
    printf("Stack: ");
    display(st);
    return 0;
}