/*Write a program that will reverse a linked list only by traversing it once and without using  extra
space.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* CreateNode(int val){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode!=NULL){
        newnode->data=val;
        newnode->next=NULL;
    }
    else{
        printf("Node not created.\n");
    }
    return newnode;
}
void printList(node* head){
    while(head!=NULL){
        printf("-->%d",head->data);
        head=head->next;
    }
    printf("\n");
}
void InsertFront(node** head,int val){
    node* newnode=CreateNode(val);
    if(newnode==NULL){
        return;
    }
    if(*head==NULL){
        *head=newnode;
    }
    else{
        newnode->next=*head;
        *head=newnode;
    }
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
    int choice;
    do{
        int value;
        printf("Enter value:");
        scanf("%d",&value);
        InsertFront(&head,value);
        printf("Choice:");
        scanf("%d",&choice);
    }while(choice!=0);
    printf("Original List:");
    printList(head);
    reverseList(&head);
    printf("Reverse List:");
    printList(head);
    return 0;
}