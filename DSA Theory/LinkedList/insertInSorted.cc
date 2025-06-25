#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *next;
};
typedef struct node node;

void searchAndDelete(node** head,int k){
    node* curr=*head;
    node* prev=NULL;
    int flag=0;
    //found at head..
    while(curr!=NULL && curr->info==k){
        node* del=curr;
        curr=curr->next;
        free(del);
        flag=1;
        *head=curr;
    }
    while(curr!=NULL){
        if(curr->info==k){
            node* del=curr;
            prev->next=curr->next;
            curr=curr->next;
            free(del);
            flag=1;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    if(!flag){
        cout<<"Delete element not found.."<<endl;
    }
}
void insertAtSort(node** head, int val) {
    node* temp=(node*)malloc(sizeof(node));
    temp->info=val;
    temp->next=NULL;
    if(*head==NULL || (*head)->info > val){
        temp->next=*head;
        *head=temp;
    }
    else{
        node* temp2=*head;
        // Find the proper position to insert
        while(temp2->next!=NULL && temp2->next->info < val){
            temp2=temp2->next;
        }
        //insert..
        temp->next=temp2->next;
        temp2->next=temp;
    }
}
void display(node *head){
    cout<<"List:";
    while(head!=NULL){
        cout<<head->info<<" ";
        head=head->next;

    }
    cout<<endl;
}
int main(){
    node *head=NULL;
    insertAtSort(&head,10);
    insertAtSort(&head,2);
    insertAtSort(&head,32);
    insertAtSort(&head,2);
    insertAtSort(&head,54);
    insertAtSort(&head,20);
    display(head);
    int del;
    cout<<"Enter element to delete:";
    cin>>del;
    searchAndDelete(&head,del);
    display(head);
    return 0;
}