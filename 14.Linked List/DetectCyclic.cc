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
    bool isCyclic(){
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){//to handle even case.. if 2 and 3
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"cyclic exist."<<endl;
                return true;
            }
        }
        cout<<"cyclic NOT exist."<<endl;
        return false;
        
    }
};
int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.tail->next=ll.head;
    ll.isCyclic();
    return 0;
}