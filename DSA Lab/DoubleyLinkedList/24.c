/*
Given a sorted doubly linked list, design an algorithm and write a program to eliminate
duplicates from this list.
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
//dispaly list...
void DisplayList(node* head){
    printf("List: ");
    while(head!=NULL){
        printf(" %d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void EliminateDuplicate(node** head){
    node* curr=*head;
    while(curr->next!=NULL){
        node* forw=curr->next;
        if(curr->data==forw->data){
            node* next=forw->next;
            curr->next=next;
            if(forw->next!=NULL){
                next->prev=curr;
            }
            free(forw);
        }
        else{
            curr=curr->next;
        }
    }
}
int main(){
    node* head=NULL;
    printf("Press[1] to InsertAtEnd.\n");
    printf("Press[2] to DisplayList.\n");
    printf("Press[3] to EliminateDuplicate.\n");
    printf("Press[0] to Exit.\n");
    int choice;
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int k;
                printf("Enter Value to InsertAtEnd:");
                scanf("%d",&k);
                InsertAtEnd(&head,k);
                break;
            }
            case 2:{
                DisplayList(head);
                break;
            }
            case 3:{
                EliminateDuplicate(&head);
                printf("Duplicate Removed.\n");
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