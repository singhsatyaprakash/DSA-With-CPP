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
bool validateHelper(node* root,node* min,node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data < min->data){
        return false;
    }
    if(max!=NULL && root->data > max->data){
        return false;
    }
    return validateHelper(root->left,min,root) && validateHelper(root->right,root,max);
}
bool isValidate(node* root){
    return validateHelper(root,NULL,NULL);
}
int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    node* root=BulidBST(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<isValidate(root);
    return 0;
}