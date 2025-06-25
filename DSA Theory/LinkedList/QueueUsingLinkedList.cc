#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
typedef struct node node;
node* dequeue(node* top){
    if(top==NULL){
        cout<<"Queue is empty."<<endl;
        return NULL;
    }
    else{
    node* temp=top;
    top=top->next;
    cout<<"Dequeue value is:"<<temp->info<<endl;
    temp->next=NULL;//delete
    }
    return top;
}
void enqueue(node** head,node** last,int val){
    node* temp=(node*)malloc(sizeof(node));
    temp->info=val;
    temp->next=NULL;
    if(*head==NULL){
        *head=*last=temp;
    }
    else{
        (*last)->next=temp;
        *last=temp;
    }
}
void display(node* head){
    while(head!=NULL){
        cout<<head->info<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    node* head=NULL;
    node* last=NULL;
    //enqueue element in queue..
    enqueue(&head,&last,21);
    enqueue(&head,&last,22);
    enqueue(&head,&last,23);
    enqueue(&head,&last,24);
    enqueue(&head,&last,25);
    cout<<"Queue:";
    display(head);
    head=dequeue(head);
    head=dequeue(head);
    head=dequeue(head);
    cout<<"Queue:";
    display(head);
    return 0;
}
