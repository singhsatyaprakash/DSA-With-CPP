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
bool isIdentical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    if(root1->data!=root2->data){
        return false;
    }
    return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
}
bool isSubTree(Node* root,Node* subroot){
    if(root==NULL && subroot==NULL){
        return true;
    }
    if(root==NULL || subroot==NULL){
        return false;
    }
    if(root->data==subroot->data){
        if(isIdentical(root,subroot)){
            return true;
        }
    }
    int isLeftSubtree=isSubTree(root->left,subroot);
    if(!isLeftSubtree){
        return isSubTree(root->right,subroot);
    }
    return true;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root=BulidTree(nodes);
    Node* subroot = new Node(2);
    subroot->left = new Node(4);
    subroot->right = new Node(6);
    isSubTree(root,subroot)?(cout<<"True"):(cout<<"False");
    return 0;
}