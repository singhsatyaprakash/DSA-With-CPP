#include<iostream>
using namespace std;

void enqueue(int q[],int *front,int *rear,int value,int n){
    if(*rear==n-1){
        cout<<"Queue is full.."<<endl;
        return;
    }else{
        if(*front==-1){
            (*front)++;
        }
        (*rear)++;
        q[*rear]=value;
    }
}
void display(int q[],int front,int rear){
    if(front==-1){
        cout<<"Queue is empty.."<<endl;
        return;
    }
    for(int i=front;i<=rear;i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;
}
int dequeue(int q[],int *front,int *rear){
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
    int n,numElements,numDequeues,value;
    cout<<"Enter the size of the queue: ";
    cin >> n;
    int q[n];
    int front=-1,rear=-1;
    cout<<"How many elements to enqueue: ";
    cin>>numElements;
    for(int i=0;i<numElements;i++){
        cout<<"Enter value"<< i + 1 << " : ";
        cin>>value;
        enqueue(q,&front,&rear,value,n);
    }
    display(q,front,rear);//Displaying Queue
    cout<<"Enter the number of elements to dequeue: ";
    cin>>numDequeues;  
    for(int i=0;i<numDequeues;i++){
        int dequeuedValue=dequeue(q,&front,&rear);
        if(dequeuedValue!=-1){
            cout<<"Deleted value is: "<<dequeuedValue<<endl;
        }
        else{
            break;
        }
        display(q,front,rear);
    } 
    return 0;
}
