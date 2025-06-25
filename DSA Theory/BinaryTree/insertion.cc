#include<iostream>
using namespace std;
typedef struct Node{
    int key;
    struct Node *left,*right;
}node;
node* newnode(int key){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        cout<<"Node not created."<<endl;
        return NULL;
    }
    newnode->key=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insertNode(node* root,int key){
    if(root==NULL){
        return newnode(key);
    }
    if(root->key==key){
        return root;//duplicate
    }
    if(root->key >key){
        root->left=insertNode(root->left,key);
    }
    if(root->key < key){
        root->right=insertNode(root->right,key);
    }
    return root;
}
void inorderDisplay(node* root){
    if(root!=NULL){
        inorderDisplay(root->left);
        cout<<root->key<<" ";
        inorderDisplay(root->right);
    }
}
int main(){
    node* root=NULL;
    root=insertNode(root,12);
    root=insertNode(root,10);
    root=insertNode(root,4);
    root=insertNode(root,2);
    root=insertNode(root,56);
    root=insertNode(root,67);
    root=insertNode(root,89);
    root=insertNode(root,32);
    inorderDisplay(root);
    return 0;
}
