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
bool search(node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(root->data >key){//call for search in left subtree(low)
       return search(root->left,key);
    }
    else{//search in right subtree..
        return search(root->right,key);
    }
    return false;

}
int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    node* root=BulidBST(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<(search(root,15)?"Found":"Not found")<<endl;
    return 0;
}