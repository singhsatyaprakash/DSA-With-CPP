/*
Swapping Nodes in a Linked List
We have a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. Swapping data of nodes may be expensive in many situations when data contains many fields. It may be assumed that all keys in the linked list are distinct.
Sample Input 1 : 1->2->3->4, x = 2, y = 4
Sample Output 1 : 1->4->3->2
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
    while(head != nullptr){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

Node* swapNodesInLinkedList(int x, int y, Node* head){
    if(x == y) return head;  // No need to swap if x and y are the same

    Node *prevX = nullptr, *currX = head;
    Node *prevY = nullptr, *currY = head;

    // Find x and its previous node
    while(currX && currX->data != x){
        prevX = currX;
        currX = currX->next;
    }

    // Find y and its previous node
    while(currY && currY->data != y){
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not found, return the list as is
    if(currX == nullptr || currY == nullptr) return head;

    // If x is not head of the list
    if(prevX != nullptr)
        prevX->next = currY;
    else
        head = currY;  // make y the new head

    // If y is not head of the list
    if(prevY != nullptr)
        prevY->next = currX;
    else
        head = currX;  // make x the new head

    // Swap next pointers
    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;
}

int main(){
    List ll;
    int size;
    cout << "How many elements in List: ";
    cin >> size;

    // Pushing values into list
    for(int i = 0; i < size; i++){
        ll.push_front(size - i);
    }

    int x, y;
    cout << "Enter values to swap: ";
    cin >> x >> y;

    cout << "Before swapping:" << endl;
    PrintList(ll.head);

    ll.head = swapNodesInLinkedList(x, y, ll.head);

    cout << "After swapping:" << endl;
    PrintList(ll.head);

    return 0;
}

/*
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
Node* swappingNodesInLinkedList(int x,int y,Node* head){
    // No need to swap if x and y are the same
    if(x==y){
        return head;
    }  
    Node* temp=head;//to return the list..
    Node* firsthead=nullptr;
    Node* secondhead=nullptr;
    Node* prevfirst=nullptr;
    Node* prevsecond=nullptr;
    Node* nextfirst=nullptr;
    Node* nextsecond=nullptr;
    Node* prev=nullptr;
    Node* curr=head;
    Node* forw=curr->next;
    //finding x and y data nodes...
    while(curr!=nullptr){
        if(curr->data==x){
            prevfirst=prev;
            firsthead=curr;
            nextfirst=curr->next;
        }
        if(curr->data==y){
            prevsecond=prev;
            secondhead=curr;
            nextsecond=curr->next;
        }
        if(firsthead!=nullptr && secondhead!=nullptr){
            prevfirst->next=secondhead;
            prevsecond->next=firsthead;
            firsthead->next=nextsecond;
            secondhead->next=nextfirst;
            break;
        }
        prev=curr;
        curr=curr->next;
        forw=curr->next;
    }
    return temp;
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
    int x,y;
    cout<<"Enter values to swap:";
    cin>>x;
    cin>>y;
    cout<<"Before swapping:"<<endl;
    PrintList(ll.head);
    ll.head=swappingNodesInLinkedList(x,y,ll.head);
    cout<<"After swapping:"<<endl;
    PrintList(ll.head);
    return 0;
}*/