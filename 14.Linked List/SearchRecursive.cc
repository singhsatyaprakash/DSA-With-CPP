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
    int helper(Node* head,int key){
        if(head==NULL){
            return -1;
        }
        if(head->data==key){
            return 0;
        }
        int idx=helper(head->next,key);
        if(idx==-1){
            return -1;
        }
        return idx+1;
    }
    int searchRec(int key){
        return helper(head,key);
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
    int key;
    cout<<"Enter element to search in list:";
    cin>>key;
    cout<<"Element found at index:"<<ll.searchRec(key)<<endl;
    return 0;
}