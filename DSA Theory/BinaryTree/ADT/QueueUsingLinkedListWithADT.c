#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct queue{
    node* front;
    node* rear;
}queue;
queue* initilaise_Queue(){
    //need to allocate memory beacause two nodepointing address...
    queue* q=(queue*)malloc(sizeof(queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}
node* CreateNode(int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void enqueue(queue* q,int data){
    node* newnode=CreateNode(data);
    if(!newnode){
        printf("Not sufficient Memory.\n");
    }
    else{
        if(q->front==NULL){
            q->front=newnode;
            q->rear=newnode;
        }
        else{
            (q->rear)->next=newnode;
            q->rear=newnode;
        }
    }
}
int dequeue(queue* q){
    if(q->front==NULL){
        printf("Queue is Empty..\n");
        return INT_MIN;
    }
    else{
        int k=(q->front)->data;
        node* del=q->front;
        q->front=(q->front)->next;
        del->next=NULL;
        free(del);
        return k;
    }
}
void dispaly(queue* q){
    node* temp=q->front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    queue* q=initilaise_Queue();
    enqueue(q,55);
    enqueue(q,56);
    enqueue(q,57);
    enqueue(q,58);
    enqueue(q,59);
    printf("Queue:");
    dispaly(q);
    enqueue(q,60);
    printf("Delete element:%d\n",dequeue(q));
    printf("Delete element:%d\n",dequeue(q));
    printf("Delete element:%d\n",dequeue(q));
    printf("Queue:");
    dispaly(q);
    enqueue(q,100);
    printf("Queue:");
    dispaly(q);
    return 0;
}