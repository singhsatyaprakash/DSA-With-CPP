#include<iostream>
using namespace std;
class Node{
    string key;
    int val;
    Node* next;
public:
    Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
    }
};
class HashTable{
    int totSize;
    int currSize;//rehashing
    Node** table;
public:
    HashTable(int size=5){
        totSize=size;
        currSize=0;
        table=new Node*[size];
        for(int i=0;i<size;i++){
            table[i]=NULL;
        }
    }
};
void insert(string key,int val){

}
void search(string key){

}
void remove(string key){

}
int main(){
    HashTable ht;
    return 0;
}