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
void printInRange(node* root,int start,int end){
    if(root==NULL){
        return;
    }
    if(start<=root->data && root->data<=end){
        printInRange(root->left,start,end);
        cout<<root->data<<" ";
        printInRange(root->right,start,end);
    }
    else if(root->data<start){
        printInRange(root->right,start,end);
    }
    else if(root->data>end){
        printInRange(root->left,start,end);
    }
}
int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    node* root=BulidBST(arr,sizeof(arr)/sizeof(arr[0]));
    printInRange(root,5,10);
    
    return 0;
}