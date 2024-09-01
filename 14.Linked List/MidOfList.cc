#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head=NULL;
        tail=NULL;
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ==> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    int MidOfList(){
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){//to handle even case.. if 2 and 3
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};
int main(){
    List ll;
    int n;
    cout<<"How many element to push:";
    cin>>n;
    for(int i=1;i<=n;i++){
        ll.push_back(i*i);
    }
    ll.printList();
    cout<<"Mid of list:"<<ll.MidOfList()<<endl;
    return 0;
}