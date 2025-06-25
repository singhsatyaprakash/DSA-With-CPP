/*Problem Statement 29:  Given a linked list and a number n, design an algorithm and write a program to find the value at
the n'th node from end of this linked list.
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
int SizeOfList(node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
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
int getNthNode(node* head,int n){
    int size=SizeOfList(head);
    for(int i=0;i<size-n;i++){
        head=head->next;
    }
    return head->data;
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
    int n;
    printf("Enter which node from last (n):");
    scanf("%d",&n);
    int res=getNthNode(head,n);
    printf("%dth Node from last is:%d",n,res);
    return 0;
}