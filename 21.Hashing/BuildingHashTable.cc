//Linkedlist: Chaining Hashing
#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    string key;
    int value;
    Node* next;
    Node(string key,int value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    //before deleting the node it call to delete the node in it next if exists.
    ~Node(){
        if(next!=NULL){//if node have next node delete it...
            delete next;
            next=NULL;
        }
    }
};
class HashTable{
    int totSiz;
    int currSiz;//use in rehasing
    Node** table;//node* type array store the address of node.
    //private function..
    int hashFunction(string key){
        int idx=0;
        for(int i=0;i<key.size();i++){
            idx=idx+(key[i]*key[i])%totSiz;
        }
        return idx % totSiz;
    }
    void rehash(){  //O(n)
        Node** oldTable=table;
        int oldSize=totSiz;
        totSiz=2*totSiz;
        currSiz=0;
        table=new Node*[totSiz];//here we are creating a pure new table .. NOt increaing the size of old table..
        for(int i=0;i<totSiz;i++){
            table[i]=NULL;
        }
        //copy old values..
        for(int i=0;i<oldSize;i++){
            Node* temp=oldTable[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            if(oldTable[i]!=NULL){
                delete oldTable[i]; //delete only head node all linked node so we have to write destructor to delete each node
            }
        }
        //now our old table is filled with NULL and not in use we have to delete it.
        delete[] oldTable;
    }

    public:
    HashTable(int size=5){
        totSiz=size;
        currSiz=0;
        table=new Node*[totSiz];
        for(int i=0;i<totSiz;i++){
            table[i]=NULL;
        }
    }

    void insert(string key,int value){ //O(1) for insertion but if rehash  happend O(n) in worst case.
        int idx=hashFunction(key);
        //create newnode...
        Node* newnode=new Node(key,value);
        newnode->next=table[idx];
        table[idx]=newnode;
        currSiz++;
        double lamda=currSiz/(double)totSiz;
        if(lamda>1){
            rehash();
        }
    }
    bool exists(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    int search(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return  temp->value;
            }
            temp=temp->next;
        }
        return -1;
    }
    void remove(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];
        Node* prev=temp;
        while(temp!=NULL){
            if(temp->key==key){//erase
                if(prev==temp){//head
                    table[idx]=temp->next;
                }
                else{
                    prev->next=temp->next;
                }
                return;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    void print(){
        for(int i=0;i<totSiz;i++){
            cout<<"idx"<<i<<"-->";
            Node* temp=table[i];
            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<temp->value<<")"<<"-->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    HashTable ht;
    ht.insert("India",150);
    ht.insert("US",50);
    ht.insert("Russia",100);
    ht.insert("Nepal",20);
    ht.insert("China",150);
    // ht.insert("UK",10);
    ht.print();
    string key;
    cout<<"Enter key to search:";
    getline(cin,key);
    if(ht.exists(key)){
        cout<<"Population of "<<key<<" is: "<<ht.search(key);
        cout<<endl;
    }else{
        cout<<"Key Not exists."<<endl;
    }
    cout<<"Enter key to remove:";
    getline(cin,key);
    if(ht.exists(key)){
        cout<<"Population of "<<key<<" is: ";
        ht.remove(key);
        ht.print();
        cout<<endl;
    }else{
        cout<<"Key Not exists."<<endl;
    }
    return 0;
}
