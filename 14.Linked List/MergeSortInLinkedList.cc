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
    void push_front(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;//newNode is address..
        }
    }
    void push_back(int val){
        Node* newNode= new Node(val);
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

    //Spliting the linked list...
    Node* MidOfList(Node* head){
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;//to track th mid point and split it...
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
        prev->next=NULL;//spilt done...
        }
        return slow;//right head..
    }

    //mergeing sorted list...
    Node* mergelist(Node* left,Node* right){
        List ans;
        Node* i=left;
        Node* j=right;
        while(i!=NULL && j!=NULL){
            if(i->data<=j->data){
                  ans.push_back(i->data);
                  i=i->next;
            }else{
                ans.push_back(j->data);
                j=j->next;
            }
        }
        while(i!=NULL){
            ans.push_back(i->data);
            i=i->next;
        }
        while(j!=NULL){
            ans.push_back(j->data);
            j=j->next;
        }
        return ans.head;
    }
    
    //merge sort function...
    Node* mergesort(Node* head){
        if(head->next==NULL || head==NULL){
            return head;
        }
        Node* righthead=MidOfList(head);
        head=mergesort(head);//call to sort left half
        righthead=mergesort(righthead);//call to sort right half
        return mergelist(head,righthead);
    }
    
};
int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(1);
    ll.push_front(4);
    ll.push_front(2);
    ll.push_front(5);
    ll.printList();
    ll.head=ll.mergesort(ll.head);
    ll.printList();
    return 0;
}