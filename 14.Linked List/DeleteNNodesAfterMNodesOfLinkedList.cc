/*
Delete N Nodes After M Nodes of a Linked List
We have a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same till end of the linked list. Difficulty Level: Rookie.
Sample Input 1 : M=2 N=2 LL: 1->2->3->4->5->6->7->8
Sample Output 1 : 1->2->5->6
Sample Input 2 : M=3 N=2 LL: 1->2->3->4->5->6->7->8->9->10
Sample Output 2 : 1->2->3->6->7->8
*/
#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class List{
    public:
        Node* head;
        Node* tail;
    List(){
        head=tail=nullptr;
    }
    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
};
void PrintList(Node* head){
    while(head!=nullptr){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"nullptr"<<endl;
}
Node* DeleteNNodesAfterMNodes(int m,int n,Node* head){
    if(head==nullptr){
        return nullptrspira;
    }
    Node* prev=head;
    for(int i=0;i<m;i++){
        prev=head;
        head=head->next;
    }
    for(int j=0;j<n;j++){
        Node* del=head;
        head=head->next;
        delete del;
    }
    prev->next=head;
    return DeleteNNodesAfterMNodes(m,n,head);//recursive call...
}
int main(){
    List ll;
    int size;
    cout<<"How many element in List:";
    cin>>size;
    //pushing value in list..
    for(int i=0;i<size;i++){
        ll.push_front(size-i);
    }
    PrintList(ll.head);
    int m;
    cout<<"After how many node to delete:";
    cin>>m;
    int n;
    cout<<"How many node to delete:";
    cin>>n;
    DeleteNNodesAfterMNodes(m,n,ll.head);
    PrintList(ll.head);
    return 0;
}