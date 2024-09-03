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
    public:
    Node* head;
    Node* tail;
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
    void removeCyclic(Node* head){
        Node* slow=head;
        Node* fast=head;
        bool iscyclic=false;
        while(fast!=NULL && fast->next!=NULL){//to handle even case.. if 2 and 3
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"cyclic exist."<<endl;
                iscyclic=true;
                break;
            }
        }
        if(!iscyclic){
        cout<<"cyclic NOT exist."<<endl;
        return;
        }
        slow=head;//reinitalize slow 
        if(slow==fast){
            while(fast->next!=slow){
                fast=fast->next;
            }
            fast->next=NULL;
            cout<<"Cycle removed."<<endl;

        }else{
            Node* prev=fast;
            while(fast!=slow){
                slow=slow->next;
                prev=fast;
                fast=fast->next;
            }
            prev->next=NULL;//removing cyclic..
            cout<<"Cycle removed."<<endl;
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
};
int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.tail->next=ll.head;
    // ll.printList();
    ll.removeCyclic(ll.head);
    ll.printList();

    return 0;
}