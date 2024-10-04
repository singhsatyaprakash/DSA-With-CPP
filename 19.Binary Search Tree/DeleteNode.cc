#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *left,*right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};
node* insert(node* root,int val){
    if(root==NULL){
        root=new node(val);
        return root;
    }
    if(val>root->data){
        root->right=insert(root->right,val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    return root;
}
node* BulidBST(int arr[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
//inorder...
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* getInorderSucessor(node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
node* delNode(node* root,int val){
    if(root==NULL){
        return NULL;
    }
    //searching that node to be delete...
    if(root->data > val){//left me delete hoga..
        root->left=delNode(root->left,val);
    }
    else if(root->data < val){///right me delete hoga..
        root->right=delNode(root->right,val);//return updated adrress...
    }
    else{//root->data==val
        //case 1: if node to be delete is leaf i.e no child..
        if(root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }
        //case 2:if node to be delete has one child...
        if(root->left==NULL || root->right==NULL){
            return root->left==NULL? root->right:root->left;///agar left null hai tho return right node & viceversa..
        }
        //case 3: Two children
        node* IS=getInorderSucessor(root->right);//inordersuceessor left most node in right subtree...
        //replace valueof node to delete with value of IS val..
        root->data=IS->data;
        //delete the IS node...
        root->right=delNode(root->right,IS->data);
        return root;
    }
    return NULL;//never hit this case..
}
int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    node* root=BulidBST(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<"Intial tree:";
    inorder(root);
    root=delNode(root,4);
    cout<<"\nAfter deletion tree:";
    inorder(root);
    return 0;
}