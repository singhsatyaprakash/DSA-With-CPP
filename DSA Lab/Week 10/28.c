/*Problem statement 28: Write an algorithm that will split a linked list into two linked lists, so that successive nodes go to
different lists. Odd numbered nodes to the first list while even numbered nodes to the second list.
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
void splitLinkedlist(node* head){
    node* oddNumberedList=CreateNode(0);
    node* evenNumberedList=CreateNode(0);
    node* odd=oddNumberedList;
    node* even=evenNumberedList;
    int n=SizeOfList(head);
    for(int i=0;i<n;i++){
        if(i%2==0){
            odd->next=head;
            odd=odd->next;
        }
        else{
            even->next=head;
            even=even->next;
        }
        head=head->next;
    }
    odd->next=NULL;
    even->next=NULL;
    printf("Odd Numbered list:");
    printList(oddNumberedList->next);
    printf("Even Numbered list:");
    printList(evenNumberedList->next);
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
    splitLinkedlist(head);
    return 0;
}