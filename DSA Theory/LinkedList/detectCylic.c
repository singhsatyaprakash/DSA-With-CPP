#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
bool Hascycle(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
void insertAtLast(node** head,node** last,int val){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;
    if(*head==NULL){
        *head=*last=temp;
    }
    else{
        (*last)->next=temp;
        *last=temp;
    }
}
int main(){
    //cyclic List 1....
    node* head1=NULL;
    node* tail1=NULL;
    //creating cyclic list 1..
    insertAtLast(&head1,&tail1,11);
    insertAtLast(&head1,&tail1,12);
    insertAtLast(&head1,&tail1,13);
    insertAtLast(&head1,&tail1,14);
    insertAtLast(&head1,&tail1,15);
    tail1->next=head1;
    if(Hascycle(head1)){
        printf("\nList 1 is cyclic list..\n");
    }
    else{
        printf("\nList 1 is Not cyclic...\n");
    }
    //List 2....
    node* head2=NULL;
    node* tail2=NULL;
    //creating normal list..
    insertAtLast(&head2,&tail2,51);
    insertAtLast(&head2,&tail2,52);
    insertAtLast(&head2,&tail2,53);
    insertAtLast(&head2,&tail2,54);
    insertAtLast(&head2,&tail2,55);
    if(Hascycle(head2)){
        printf("\nList 2 is cyclic list..\n");
    }
    else{
        printf("\nList 2 is Not cyclic...\n\n");
    }

    return 0;
}