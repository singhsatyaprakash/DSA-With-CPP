#include<iostream>
using namespace std;
class Node{//represent each element of linked list..
public:
    int data;
    Node* next;
    //Constructor to assign value in node..
    Node(int val){
        data=val;
        next=NULL;//here element are single not linked yet...
    }
    ~Node(){
        // cout<<"Destuctor for node data "<<data<<endl;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Destuctor for node data "<<data<<endl;
    }
};
class List{//class to link all element with each other...
    Node* head;//to remember the starting point of list..
    Node* tail;//to remember the ending point of list..
    public:
    //constructor to link the list..
    List(){
        head=NULL;//initially head and tail are at same point and Null..
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
    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ==> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    ~List(){
        cout<<"~List"<<endl;
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }
};
int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    return 0;
}