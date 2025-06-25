/*
Problem Statement 22.Given a doubly linked list, design an algorithm and write a program to reverse this list without using any extra space.
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
node* CreateNode(int data){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode!=NULL){
        newnode->data=data;
        newnode->next=NULL;
    }
    return newnode;
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
//dispaly list...
void DisplayList(node* head){
    printf("List: ");
    while(head!=NULL){
        printf(" %d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void ReverseTheList(node** head){
    node* curr=*head;
    node* temp=NULL;
    while(curr!=NULL){
        //swap address...      
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        if(curr->prev==NULL){
            *head=curr;
        }
        curr=curr->prev;
    }
}
int main(){
    node* head=NULL;
    printf("Press[1] to InsertAtFront.\n");
    printf("Press[2] to DisplayList.\n");
    printf("Press[3] to ReverseTheList.\n");
    printf("Press[0] to Exit.\n");
    int choice;
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int k;
                printf("Enter Value to InsertAtFront:");
                scanf("%d",&k);
                InsertAtFront(&head,k);
                break;
            }
            case 2:{
                DisplayList(head);
                break;
            }
            case 3:{
                ReverseTheList(&head);
                printf("List reversed.\n");
                break;
            }
            case 0:{
                printf("Exit.\n");
                break;
            }
            default:printf("Invalid! Choice.\n");
        }
    } while(choice!=0);
    return 0;
}