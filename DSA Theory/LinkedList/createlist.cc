#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
typedef struct node node;
node* insert(node* head,int val){
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
node* pop(node* top){
    if(top==NULL){
        cout<<"No nodes avialable"<<endl;
        return NULL;
    }
    else{
    node* temp=top;
    top=top->next;
    cout<<"Deleted value is:"<<temp->info<<endl;
    temp->next=NULL;//delete
    }
    return top;
}
void insertAtLast(node** head,node** last,int val){
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
        cout<<head->info<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    node* last=NULL;
    // //push at front...
    // head=insert(head,10);
    // head=insert(head,20);
    // head=insert(head,30);
    // head=insert(head,40);
    // head=insert(head,50);
    insertAtLast(&head,&last,21);
    insertAtLast(&head,&last,22);
    insertAtLast(&head,&last,23);

    display(head);
    head=pop(head);
    display(head);
    // head=pop(head);
    // display(head);
    // head=pop(head);
    // display(head);
    // head=pop(head);
    // display(head);
    // head=pop(head);
    // display(head);
    // head=pop(head);
    return 0;
}
