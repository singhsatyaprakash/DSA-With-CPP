#include<iostream>
using namespace std;
void enqeue(int q[],int *front,int *rear,int value,int n){
    if(*rear==n-1){
        cout<<"Queue is full.."<<endl;
        return;
    }
    else{
        if(*front==-1){
            (*front)++;
        }
            (*rear)++;
            q[*rear]=value;
    }
}
void dispaly(int q[], int front,int rear){
    for(int i=front;i<=rear;i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;
    return;
}
int Dequeue(int q[],int *front,int *rear){
    int k;
    if(*front==-1){
        cout<<"Queue is empty.."<<endl;
        return -1;
    }
    else{
        k=q[*front];
        (*front)++;
        if(*front>*rear){
            *front=-1;
            *rear=-1;
        }
    }
    return k;
}
int main(){
    int n;
    cout<<"Enter the size of queue:";
    cin>>n;
    int q[n];
    int front=-1,rear=-1;
    enqeue(q,&front,&rear,12,n);
    enqeue(q,&front,&rear,13,n);
    enqeue(q,&front,&rear,14,n);
    enqeue(q,&front,&rear,15,n);
    enqeue(q,&front,&rear,16,n);
    dispaly(q,front,rear);
    cout<<"Deleted value is:"<< Dequeue(q,&front,&rear)<<endl;
    dispaly(q,front,rear);
    cout<<"Deleted value is:"<< Dequeue(q,&front,&rear)<<endl;
    dispaly(q,front,rear);
    cout<<"Deleted value is:"<< Dequeue(q,&front,&rear)<<endl;
    dispaly(q,front,rear);
    cout<<"Deleted value is:"<< Dequeue(q,&front,&rear)<<endl;
    dispaly(q,front,rear);
    cout<<"Deleted value is:"<< Dequeue(q,&front,&rear)<<endl;
    dispaly(q,front,rear);
    cout<<"Deleted value is:"<< Dequeue(q,&front,&rear)<<endl;
    return 0;
}