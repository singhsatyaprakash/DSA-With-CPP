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
    int getsize(){
        Node* temp=head;
        int sz=0;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }
        return sz;
    }
    void removeNth(int k){
        int size=getsize();
        cout<<size<<endl;
        Node* prev=head;
        for(int i=0;i<(size-k-1);i++){
            prev=prev->next;
        }
        Node* todel=prev->next;
        cout<<"Removed element is:"<<todel->data<<endl;
        prev->next=prev->next->next;
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
    int k;
    cout<<"Enter position to remove element from  last:";
    cin>>k;
    ll.removeNth(k);
    ll.printList();
    return 0;
}