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
};
    void printList(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ==> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    //Spliting the linked list...
    Node* splitAtMid(Node* head){
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

    //reversinh list...
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;//store
            curr->next=prev;//reverse
            prev=curr;//update
            curr=next;//update  
        }
        return prev;//prev become head..
    }

    
    Node* ZigZag(Node* head){
        Node* righthead=splitAtMid(head);
        Node* rightheadRev=reverse(righthead);
        //now zig zag: 1st:head  2nd:rightheadrev
        Node* left=head;
        Node* right=rightheadRev;
        Node* tail=right;//for odd case number of node in list right one always have one charcter while spilting...
        //Alternate merging...
        while(left!=NULL&&right!=NULL){
            Node* nextleft=left->next;//to store the address and comback to join...
            Node* nextright=right->next;
            //zig-zag...
            left->next=right;
            right->next=nextleft;
            tail=right;
            //moving forward..
            left=nextleft;
            right=nextright;
        }
        if(right!=NULL){
            tail->next=right;//isiliye tail ko phele stor kar liya tha...
        }
        return head;
    }
    
int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    printList(ll.head);
    ll.head=ZigZag(ll.head);
    printList(ll.head);
    return 0;
}