#include<iostream>
#include<vector>
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
void printpath(vector<int>path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void pathhelper(node* root,vector<int>&path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        printpath(path);
        path.pop_back();
        return;
    }
    pathhelper(root->left,path);
    pathhelper(root->right,path);
    path.pop_back();
}
void pathRootToLeaf(node* root){
    vector<int>path;
    pathhelper(root,path);
}
int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    node* root=BulidBST(arr,sizeof(arr)/sizeof(arr[0]));
    pathRootToLeaf(root);
    return 0;
}