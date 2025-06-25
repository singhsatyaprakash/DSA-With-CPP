#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void insertAtLast(node** head,node** tail,int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    if(*head==NULL){
        *head=*tail=newnode;
        (*head)->next=*head;//circular
    }
    else{
        (*tail)->next=newnode;
        *tail=newnode;
        (*tail)->next=*head;

    }
}
void insertAtFront(node** head,int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
        (*head)->next=*head;//cirucular...
    }
    else{
        node* temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=*head;
        *head=newnode;
    }
}
void insertAtBetween(node **head, int pos, int val) {
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    node* temp=*head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void display(node* head){
    node* temp=head;
    while(temp->next!=head){
        printf("%d --> ",temp->data);
        temp=temp->next;
    }
    printf("%d --> ",temp->data);
    printf("HEAD\n");
}
int main(){
    node* head=NULL;
    node* tail=NULL;
    //insert at last...
    insertAtLast(&head,&tail,51);
    insertAtLast(&head,&tail,52);
    insertAtLast(&head,&tail,53);
    printf("List After insert at last:\n");
    display(head);
    //insertion at front..
    insertAtFront(&head,13);
    insertAtFront(&head,12);
    insertAtFront(&head,11);
    printf("List After insert at front:\n");
    display(head);
    //insert at position in b/w list...
    int pos;
    printf("Enter pos(>=1) at which insert:\n");
    scanf("%d",&pos);
    insertAtBetween(&head,pos,1000);
    printf("List after Insert At Between:\n");
    display(head);
    return 0;
}