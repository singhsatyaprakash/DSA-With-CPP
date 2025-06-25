#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void insertAtFront(node **head,int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        newnode->next=*head;
        *head=newnode;
    }
}
void display(node* head){
    while(head!=NULL){
        printf("%d --> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
void reverseList(node** head){
        node* curr=*head;
        node* prev=NULL;
        while(curr!=NULL){
            node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        *head=prev;
    }
int main(){
    node* head=NULL;
    //creating list..
    insertAtFront(&head,1);
    insertAtFront(&head,2);
    insertAtFront(&head,3);
    insertAtFront(&head,4);
    insertAtFront(&head,5);
    printf("Original list:\n");
    display(head);
    //reverse the list..
    reverseList(&head);
    printf("Reveresed List:\n");
    display(head);
    return 0;
}