/*
Write an algorithm and a program to implement doubly linked list. The program should
implement following operations:
a) Create(k) - create a doubly linked list node with value k.
b) InsertFront(k) - insert node at the front of the linked list.
c) InsertEnd(k) - insert a node at the end of the linked list.
d) InsertIntermediate(k,p) - insert a node at specific position p.
e) DeleteFront() - delete a node from the front of the linked list.
f) DeleteEnd() - delete a node from the end of the linked list.
g)DeleteIntermediate(p) – delete a node from a specific position p.
h)Size() - returns the size of doubly linked list.
i) IsEmpty() - checks whether the list is empty or not.
j) FindMiddle() - returns the contents of middle node of the list.
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
//function to create node...
node* CreateNode(int value){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("Node not Created.\n");
        return NULL;
    }
    else{
        newnode->data=value;
        newnode->prev=NULL;
        newnode->next=NULL;
        return newnode;
    }
}
//function to insert at front in list...
void InsertAtFront(node** head,int value){
    //create node..
    node* newnode=CreateNode(value);
    if(newnode==NULL){
        return;
    }
    if(*head==NULL){
        *head=newnode;
    }
    else{
        newnode->next=*head;
        (*head)->prev=newnode;
        *head=newnode;
    }
}
//function to insert at last in list...
void InsertAtEnd(node** head,int value){
    node* newnode=CreateNode(value);
    if(*head==NULL){
        *head=newnode;
    }
    else{
        node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}
//function to insert at intermediate position...
void InsertIntermediate(node** head,int pos,int value){
    node* newnode=CreateNode(value);
    if(*head==NULL || pos==1){
        InsertAtFront(head,value);
    }
    else{
        node* temp=*head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
    }
}
//function to delete from front...
void DeleteFront(node **head){
    if(*head==NULL){
        printf("Cannot delete..");
        return;
    }
    else{
        node* del=*head;
        if((*head)->next!=NULL){
            *head=(*head)->next;
        }
        (*head)->prev=NULL;
        free(del);
    }
    printf("Delete done.\n");
}
void DeleteEnd(node **head){
    node* temp=*head;
    if((*head)->next==NULL){
        free(*head);
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node* del=temp->next;
    temp->next=NULL;
    free(del);
    printf("Delete done.\n");
}
void DeleteAnyWhere(node **head,int pos){
    node* temp=*head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    node* del=temp->next;
    node* temp2=del->next;
    temp->next=temp2;
    if(temp2!=NULL){
        temp2->prev=temp;
    }
    free(del);
}
//function to find size of list...
int SizeOfList(node* head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
//function to check list is empty or not?..
void IsEmpty(node* head){
    if(head==NULL){
        printf("List is empty.\n");
    }
    else{
        printf("Not empty.\n");
    }
}
//function to find the content of middle of list..
int findMiddle(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
//display function of list...
void DisplayList(node* head){
    printf("DoubleyList:");
    while(head!=NULL){
        printf(" %d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    node* head=NULL;
    int choice,value;
    printf("Press[1]  to CreateNode.\n");
    printf("Press[2]  to InsertAtFront.\n");
    printf("Press[3]  to InsertAtEnd.\n");
    printf("Press[4]  to InsertIntermediate\n");
    printf("Press[5]  to DeleteFront.\n");
    printf("Press[6]  to DeleteEnd.\n");
    printf("Press[7]  to DeleteIntermediate.\n");
    printf("Press[8]  to SizeOfList.\n");
    printf("Press[9]  to IsEmpty.\n");
    printf("Press[10] to FindMiddle.\n");
    printf("Press[11] to DisplayList.\n");
    printf("Press[0]  to Exit.\n");
    do{
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                CreateNode(0);
                break;
            }
            case 2:{
                printf("Enter value to InsertAtFront:");
                scanf("%d",&value);
                InsertAtFront(&head,value);
                break;
            }
            case 3:{
                printf("Enter value to InsertAtEnd:");
                scanf("%d",&value);
                InsertAtEnd(&head,value);
                break;

            }
            case 4:{
                int pos;
                printf("Enter position at which to insert:");
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
                DeleteAnyWhere(&head,pos);
                break;
            }
            case 8:{
                int k=SizeOfList(head);
                printf("Size of List:%d\n",k);
                break;
            }
            case 9:{
                IsEmpty(head);
                break;
            }
            case 10:{
                int k=findMiddle(head);
                printf("Middle is: %d\n",k);
                break;
            }
            case 11:{
                DisplayList(head);
                break;
            }
            case 0:{
                printf("Exit.\n");
                break;
            }
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice!=0);
    return 0;
}