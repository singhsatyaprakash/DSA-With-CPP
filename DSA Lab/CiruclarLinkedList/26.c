/*
Problem Statement 26. Design an algorithm and write a program to concatenate two circularly linked lists.
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
    struct node* prev;
}node;
node* CreateNode(int val){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode!=NULL){
        newnode->data=val;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else{
        printf("Node not created.\n");
    }
    return newnode;
}
void InsertAtEnd(node** head,int value){
    node* newnode=CreateNode(value);
    if(*head==NULL){
        *head=newnode;
        (*head)->next=*head;
        (*head)->prev=*head;
    }
    else{
        node* temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=*head;
        (*head)->prev=newnode;
    }
}
void DisplayList(node* head){
    if(head==NULL){
        printf("\n");
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
node* MergeList(node** head1,node** head2){
    if(*head1==NULL){
        return *head2;
    }
    else if(*head2==NULL){
        return *head1;
    }
    else if(*head1==NULL && *head2==NULL){
        return NULL;
    }
    node* temp1=*head1;
    node* temp2=*head2;
    while(temp1->next!=*head1){
        temp1=temp1->next;
    }
    while(temp2->next!=*head2){
        temp2=temp2->next;
    }
    //merge..
    temp1->next=*head2;
    (*head2)->prev=temp1;
    temp2->next=*head1;
    (*head1)->prev=temp2;
    return *head1;
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    printf("Press[1] to InsertEnd.\n");
    printf("Press[0] to ExitCreatingCircluarList.\n");
    int choice;
    printf("CREATE LIST 1:\n");
    do{
        int value;
        printf("Enter value to Insert:");
        scanf("%d",&value);
        InsertAtEnd(&head1,value);
        printf("Choice:");
        scanf("%d",&choice);
    }while(choice!=0);
    printf("CREATE LIST 2:\n");
    do{
        int value;
        printf("Enter value to Insert:");
        scanf("%d",&value);
        InsertAtEnd(&head2,value);
        printf("Choice:");
        scanf("%d",&choice);
    }while(choice!=0);
    printf("List 1:");
    DisplayList(head1);
    printf("List 2:");
    DisplayList(head2);
    node* head=MergeList(&head1,&head2);
    printf("Merge List:");
    DisplayList(head);
    return 0;
}