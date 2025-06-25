#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
typedef struct node node;
node* push(node* head,int val){
    if(head==NULL){
        head=(node*)malloc(sizeof(node));
        head->info=val;
        head->next=NULL;
    }
    else{
        node* newnode;
        newnode=(node*)malloc(sizeof(node));
        newnode->info=val;
        newnode->next=head;
        head=newnode;
    }
    return head;
}
node* pop(node* head){
    if(head==NULL){
        cout<<"Stack is empty."<<endl;
        return NULL;
    }
    else{
    node* temp=head;
    head=head->next;
    cout<<"Poped value is:"<<temp->info<<endl;
    temp->next=NULL;//delete
    }
    return head;
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
    //push at front...
    head=push(head,10);
    head=push(head,20);
    head=push(head,30);
    head=push(head,40);
    head=push(head,50);
    cout<<"Stack:";
    display(head);
    //pop elements...
    head=pop(head);
    head=pop(head);
    head=pop(head);
    cout<<"Stack:";
    display(head);
    head=pop(head);
    head=pop(head);
    cout<<"Stack:";
    display(head);
    head=pop(head);
    return 0;
}
