#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int val){
            data=val;
            next=NULL;
            prev=NULL;
        }
};
class DoublyList{
    public:
        Node* head;
        Node* tail;
        DoublyList(){
            head=tail=NULL;
        }
        void push_front(int val){
            Node* newnode=new Node(val);
            if(head==NULL){
                head=tail=newnode;
            }else{
                newnode->next=head;
                head->prev=newnode;
                head=newnode;
            }
        }
        void pop_front(){
            Node* temp=head;
            head=head->next;
            if(head!=NULL){
                head->prev=NULL;
            }
            temp->next=NULL;
            delete temp;
        }
        void printList(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<"<=>";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    DoublyList ddll;
    ddll.push_front(11);
    ddll.push_front(12);
    ddll.push_front(13);
    ddll.push_front(14);
    ddll.push_front(15);
    ddll.printList();
    ddll.pop_front();
    ddll.printList();
    return 0;
}