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
int dist(Node* root,int n){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
    int leftDist=dist(root->left,n);
    if(leftDist!=-1){
        return leftDist+1;
    }
    int rightDist=dist(root->right,n);
    if(rightDist!=-1){
        return rightDist+1;
    }
    return -1;
}
int minDis(Node* root,int n1,int n2){
    Node* lca=LCA(root,n1,n2);
    int dist1=dist(lca,n1);//lca se n1 ki durii...
    int dist2=dist(lca,n2);

    return dist1+dist2;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root=BulidTree(nodes);
    int n1=4,n2=6;
    cout<<"Minimum distance b/w both node:"<<minDis(root,n1,n2)<<endl;
    return 0;
}