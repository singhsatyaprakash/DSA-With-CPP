/*
Problem statement 27:Write an algorithm and a program that will split a circularly linked list into two circularly linked
list provided position from where circular linked list has to be splitted.
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
int SizeOfList(node** head){
    if(*head==NULL){
        return 0;
    }
    int count=1;
    node* temp=*head;
    while(temp->next!=*head){
        count++;
        temp=temp->next;
    }
    return count;
}
void InsertEnd(node** head,int val){
    node* newnode=CreateNode(val);
    if(newnode==NULL){
        return;
    }
    if(*head==NULL){
        *head=newnode;
        (*head)->next=*head;
    }
    else{
        node* temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=*head;
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
node* splitList(node** head,int pos,int *flag){
    int size=SizeOfList(head);
    if(pos<=1 || pos>size || *head==NULL || (*head)->next==*head){
        *flag=1;
        return NULL;
    }    
    node* temp=*head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    node* head2=temp->next;
    temp->next=*head;
    node* temp2=head2;
    while(temp2->next!=*head){
        temp2=temp2->next;
    }
    temp2->next=head2;
    return head2;
}
int main(){
    node* head=NULL;
    printf("Press[1] to Insert.\n");
    printf("Press[0] to exit.\n");
    int choice;
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int value;
                printf("Enter value to Insert:");
                scanf("%d",&value);
                InsertEnd(&head,value);
                break;
            }
            case 0:{
                printf("Exit of creating List.\n");
                break;
            }
            default:
            printf("Invalid Choice!\n");
        }
    }while(choice!=0);
    printf("Original List:");
    DisplayList(head);
    //spliting the circular list ...
    int pos;
    printf("Enter position from where to split:");
    scanf("%d",&pos);
    int flag=0;
    node* head2=splitList(&head,pos,&flag);
    if(flag==0){
        printf("List 1:");
        DisplayList(head);
        printf("List 2:");
        DisplayList(head2);
    }
    else{
        printf("Split not possible.\n");
    }
    return 0;
}