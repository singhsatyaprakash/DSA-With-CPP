#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next,*prev;
}node;
void insertAtFront(node **head,int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        (*head)->prev=newnode;
        newnode->next=*head;
        *head=newnode;
    }
}
void insertAtBetween(node **head, int pos, int val) {
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(pos==1){
        newnode->next=*head;
        (*head)->prev=newnode;
        *head = newnode;
        return;
    }
    node* temp=*head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev = temp;
}

void insertAtLast(node **head,node **last,int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(*head==NULL){
        *head=*last=newnode;
    }
    else{
        newnode->prev=*last;
        (*last)->next=newnode;
        *last=newnode;
    }
}
void display(node* head){
    while(head!=NULL){
        printf("%d --> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main(){
    node* head=NULL;
    node* last=NULL;
    //insert at last...
    insertAtLast(&head,&last,14);
    insertAtLast(&head,&last,15);
    insertAtLast(&head,&last,16);
    printf("List after Insert at Last:\n");
    display(head);
    //insert at front...
    insertAtFront(&head,11);
    insertAtFront(&head,12);
    insertAtFront(&head,13);
    printf("List after insert at Front:\n");
    display(head);
    //insert at position in b/w list...
    int pos;
    printf("Enter pos(>=1) at which insert:\n");
    scanf("%d",&pos);
    insertAtBetween(&head,pos,420);
    printf("List after Insert At Between:\n");
    display(head);
    return 0;
}