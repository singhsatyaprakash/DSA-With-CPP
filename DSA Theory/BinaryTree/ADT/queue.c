#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef struct Queue{
    int front;
    int rear;
    int capacity;
    int* array;
}queue;
queue* CreateQueue(int cap){
    queue* q=(queue*)malloc(sizeof(queue));
    q->front=-1;
    q->rear=-1;
    q->capacity=cap;
    q->array=(int*)malloc(sizeof(int)*q->capacity);
    return q;
}
void enqueue(queue* q,int data){
    if(q->rear>=q->capacity-1){
        printf("Queue is Full.\n");
    }
    else{
        if(q->front==-1){
            q->front=0;
        }
        q->array[++(q->rear)]=data;
    }
}
int dequeue(queue* q){
    if(q->front==-1){
        printf("Queue is Empty.\n");
        return INT_MIN;
    }
    int k=q->array[(q->front)++];
    if(q->front>q->rear){
        q->front=q->rear=-1;
    }
    return k;
}
void dispaly(queue* q){
    int si=q->front;
    int ei=q->rear;
    for(int i=si;i<=ei;i++){
        printf("%d ",q->array[i]);
    }
    printf("\n");
}
int main(){
    queue* q=CreateQueue(5);//capacity of queue as parameter..
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
    enqueue(q,100);//stack is full beacause it is not ciruclar queue..
    printf("Queue:");
    dispaly(q);
    return 0;
}