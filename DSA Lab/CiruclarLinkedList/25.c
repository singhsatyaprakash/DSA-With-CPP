/*
Problem Statement 25:Design an algorithm and write a program to implement circular linked list. The program should
implement following operations:
a) Create(k) - creates a circular linked list node with value k.
b)InsertFront() - insert node at the front of list.
c) InsertEnd() - insert node at the end of list.
d)InsertIntermediate() - insert node at any specified position of list.
e) DeleteFront() - delete node from the front of list.
f) DeleteEnd() - delete node from the end of list.
g)DeleteIntermediate() - delete node from any specified position of list.
h)Size() - return size of circular linked list.
i) IsEmpty() - checks whether list is empty or not.
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
void InsertFront(node** head,int val){
    node* newnode=CreateNode(val);
    if(newnode==NULL){
        return;
    }
    if(*head==NULL){
        *head=newnode;
        (*head)->next=*head;
    }
    else{
        newnode->next=*head;
        node* temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=newnode;
        *head=newnode;
    }
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
void InsertIntermediate(node** head,int pos,int val){
    int size=SizeOfList(head);
    if(pos<=0 || pos>size+1){
        printf("Invalid Position.\n");
        return;
    }
    if(pos==1){
        InsertFront(head,val);
    }
    else if(pos==size+1){
        InsertEnd(head,val);
    }
    else{
        node* temp=*head;
        node* newnode=CreateNode(val);
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void DeleteFront(node** head){
    if(*head==NULL){
        printf("List is Empty.\n");
        return;
    }
    node* temp=*head;
    if(temp->next==*head){
        node* del=*head;
        printf("Delete Node:%d\n",del->data);
        *head=NULL;
    }
    else{
        while(temp->next!=*head){
            temp=temp->next;
        }
        node* del=*head;
        temp->next=(*head)->next;
        *head=(*head)->next;
        printf("Delete Node:%d\n",del->data);
        free(del);
    }
}
void DeleteEnd(node** head){
    if(*head==NULL){
        printf("List is Empty.\n");
        return;
    }
    //one node
    node* temp=*head;
    if(temp->next==*head){
        node* del=*head;
        *head=NULL;
        printf("Delete Node:%d\n",del->data);
        free(del);
    }
    else{
        while(temp->next->next!=*head){
            temp=temp->next;
        }
        node* del=temp->next;
        temp->next=*head;
        printf("Delete Node:%d\n",del->data);
        free(del);
    }
}
void DeleteIntermediate(node** head,int pos){
    int size=SizeOfList(head);
    if(*head==NULL){
        printf("List is Empty.\n");
        return;
    }
    if(pos<=0 || pos>size){
        printf("Invalid Position.\n");
        return;
    }
    if(pos==1){
        DeleteFront(head);
    }
    else if(pos==size){
        DeleteEnd(head);
    }
    else{
        node* temp=*head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        node* del=temp->next;
        temp->next=temp->next->next;
        printf("Delete Node:%d\n",del->data);
        free(del);
    }
}
void IsEmpty(node* head){
    if(head==NULL){
        printf("List is Empty.\n");
    }
    else{
        printf("List is not Empty.\n");
    }
}
void Display(node* head){
    printf("List:");
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
int main(){
    node* head=NULL;
    printf("Press[1] for CreateNode.\n");
    printf("Press[2] for InsertFront\n");
    printf("Press[3] for InsertEnd.\n");
    printf("Press[4] for InsertIntermediate.\n");
    printf("Press[5] for DeleteFront.\n");
    printf("Press[6] for DeleteEnd\n");
    printf("Press[7] for DeleteIntermediate.\n");
    printf("Press[8] for SizeOfList.\n");
    printf("Press[9] for IsEmpty.\n");
    printf("Press[10] for Display.\n");
    printf("Press[0] for Exit.\n");
    int choice,value;
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                CreateNode(0);
                break;
            }
            case 2:{
                printf("Enter value to InsertFront:");
                scanf("%d",&value);
                InsertFront(&head,value);
                break;
            }
            case 3:{
                printf("Enter value to InsertEnd:");
                scanf("%d",&value);
                InsertEnd(&head,value);
                break;
            }
            case 4:{
                int pos;
                printf("Enter position to insert:");
                scanf("%d",&pos);
                printf("Enter value to InsertIntermediate:");
                scanf("%d",&value);
                InsertIntermediate(&head,pos,value);
                break;
            }
            case 5:{
                DeleteFront(&head);
                break;
            }
            case 6:{
                DeleteEnd(&head);
                break;
            }
            case 7:{
                int pos;
                printf("Enter position at which to delete:");
                scanf("%d",&pos);
                DeleteIntermediate(&head,pos);
                break;
            }
            case 8:{
                printf("Size of List:%d\n",SizeOfList(&head));
                break;
            }
            case 9:{
                IsEmpty(head);
                break;
            }
            case 10:{
                Display(head);
                break;
            }
            case 0:{
                printf("Exit.\n");
                break;
            }
            default:
            printf("Invalid Choice!\n");
        }
    }while(choice!=0);
    return 0;
}