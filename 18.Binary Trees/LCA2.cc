#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
//function to Bulid Tree from preorder...
Node* BulidTree(vector<int>nodes){
    static int idx=-1;
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* currNode=new Node(nodes[idx]);
    currNode->left=BulidTree(nodes);
    currNode->right=BulidTree(nodes);
    return currNode;
}
Node* LCA(Node* root ,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    //agar root LCA nahi hai tho child se pucha...
    Node* leftLCA=LCA(root->left,n1,n2);// agar tere left me hai dono tho tu ban ja LCA..
    Node* rightLCA=LCA(root->right,n1,n2);

    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }
    return leftLCA==NULL? rightLCA:leftLCA;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root=BulidTree(nodes);
    int n1=5,n2=6;
    Node* lca=LCA(root,n1,n2);
    cout<<"Lowest common Ancestor: "<<lca->data<<endl;
    return 0;
}