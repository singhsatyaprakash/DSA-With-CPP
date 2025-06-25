#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
typedef struct node node;
node* insert(node* head,int key,int val){
    node* temp=head;
    int flag=0;//to flag key is found or not..
    while(temp!=NULL){
        //insertion..
        if(temp->info==key){
            flag=1;
            node* newnode=(node*)malloc(sizeof(node));
            newnode->info=val;
            newnode->next=temp->next;
            temp->next=newnode;
            return head;
        }
        temp=temp->next;
    }
    if(flag==0 || head==NULL){
        cout<<"Key not found So, element not inserted."<<endl;
    }
    return head;
}
node* pushAtFront(node* head,int val){
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
void display(node* head){
    while(head!=NULL){
        cout<<head->info<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    //push at front...
    head=pushAtFront(head,50);
    head=pushAtFront(head,40);
    head=pushAtFront(head,30);
    head=pushAtFront(head,20);
    head=pushAtFront(head,10);
    cout<<"Linked List:"<<endl;
    display(head);
    int key;
    cout<<"After which value you want to insert:";
    cin>>key;
    int input;
    cout<<"Enter element to insert:";
    cin>>input;
    cout<<"Before insertion:"<<endl;
    display(head);
    head=insert(head,key,input);
    cout<<"After insertion:"<<endl;
    display(head);
    return 0;
}
