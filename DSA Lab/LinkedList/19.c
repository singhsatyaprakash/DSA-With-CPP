/*
Write an algorithm and a program to implement singly linked list. The program should
implement following operations:
a) Create(k) - create a linked list with single node of value k
b) InsertFront(k) - insert node of value k at the front of the linked list
c) InsertEnd(k) - insert a node of value k at the end of the linked list
d) InsertAnywhere(p) - insert a node at specific position p
e) DeleteFront() - delete a node from the front of the linked list
f) DeleteEnd() - delete a node from the end of the linked list
g)DeleteAnywhere(p) - delete a node from a specific position p
h)Size() - find the size of the linked list
i) IsEmpty() - checks if the linked list is empty or not
j) FindMiddle() - finds the middle element of the linked list
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node* CreateNode(int val){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("Node not create.\n");
    }
    else{
        printf("Node Created.\n");
    }
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
void InsertAtFront(node **head,node **tail,int val){
    node* newnode=CreateNode(val);
    if(*head==NULL){
        *head=newnode;
        *tail=newnode;
    }
    else{
        newnode->next=*head;
        *head=newnode;
    }
}
void InsertAtEnd(node **head,node **tail,int val){
    node* newnode=CreateNode(val);
    if(*head==NULL){
        *head=newnode;
        *tail=newnode;
    }
    else{
        (*tail)->next=newnode;
        *tail=newnode;
    }
}
void InsertAnyWhere(node **head, int pos, int val) {
    node* newnode=CreateNode(val);
    if(pos==1){
        newnode->next=*head;
        *head=newnode;
    }
    else{
        node* temp=*head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void DeleteFront(node **head){
    if(*head==NULL){
        printf("Cannot delete..");
        return;
    }
    else{
        node* del=*head;
        *head=(*head)->next;
        free(del);
    }
    printf("Delete done.\n");
}
void DeleteEnd(node **head){
    node* temp=*head;
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
    temp->next=del->next;
    free(del);
}
int FindSize(node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
void IsEmpty(node* head){
    if(head==NULL){
        printf("List is empty.\n");
    }
    else{
        printf("Not empty.\n");
    }
}
int findMiddle(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
void DisplayList(node* head){
    while(head!=NULL){
        printf("%d --> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main(){
    node* head=NULL;
    node* tail=NULL;
    int k;
    printf("Press[1] for CreateNode\n");
    printf("Press[2] for InsertAtFront\n");
    printf("Press[3] for InsertAtEnd\n");
    printf("Press[4] for InsertAnyWhere\n");
    printf("Press[5] for DeleteFront\n");
    printf("Press[6] for DeleteEnd\n");
    printf("Press[7] for DeleteAnyWhere\n");
    printf("Press[8] for Size\n");
    printf("Press[9] for IsEmpty\n");
    printf("Press[10] for FindMiddle\n");
    printf("Press[11] for DisplayList.\n");
    printf("Press[0] for Exit.\n");
    int choice;
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1:{
            printf("Enter value:");
            scanf("%d",&k);
            CreateNode(k);
            break;
        }
        case 2:{
            printf("Enter value(InsertAtFront):");
            scanf("%d",&k);
            InsertAtFront(&head,&tail,k);
            break;
        }
        case 3:{
            printf("Enter value(InsertAtEnd):");
            scanf("%d",&k);
            InsertAtEnd(&head,&tail,k);
            break;
        }
        case 4:{
            int pos;
            printf("Enter position where to insert:");
            scanf("%d",&pos);
            printf("Enter value(InsertAnyWhere):");
            scanf("%d",&k);
            InsertAnyWhere(&head,pos,k);
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
            printf("Enter position which to delete:");
            scanf("%d",&pos);
            DeleteAnyWhere(&head,pos);
            break;
        }
        case 8:{
            printf("Size of list is:%d\n",FindSize(head));
            break;
        }
        case 9:{
            IsEmpty(head);
            break;
        }
        case 10:{
            int mid=findMiddle(head);
            printf("Middle of List is:%d\n",mid);
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
        printf("Invalid Choice.\n");
        }
    }while(choice!=0);
    return 0;
}