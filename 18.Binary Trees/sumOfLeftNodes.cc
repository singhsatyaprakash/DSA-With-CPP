    
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
int sumOfLeftLeaves(Node* root) {
    if(root==nullptr){
        return 0;
    }
    int leftSum=sumOfLeftLeaves(root->left);
    int rightSum=sumOfLeftLeaves(root->right);
    if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){
        return leftSum +rightSum + root->left->data;
    }
    return leftSum + rightSum;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root=BulidTree(nodes);
    cout<<"Sum of all left nodes:"<<sumOfLeftLeaves(root);
    return 0;
}