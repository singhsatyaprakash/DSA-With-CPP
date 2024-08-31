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
    void insert(int val,int pos){
    
        Node* newNode=new Node(val);
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"Invalid position"<<endl;
                return;
            }
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
};
int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();
    ll.insert(100,2);//(val,idx)
    ll.printList();
    return 0;
}