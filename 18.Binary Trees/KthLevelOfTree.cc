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
void KthHelper(Node* root,int k,int currlevel){
    if(root==nullptr){
        return;
    }
    if(currlevel==k){
        cout<<root->data<<" ";
    }
    KthHelper(root->left,k,currlevel+1);
    KthHelper(root->right,k,currlevel+1);
}
void KthLevelOfTree(Node* root, int k){
    KthHelper(root,k,1);//(root, level,currlevel);
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root=BulidTree(nodes);
    int k;
    cout<<"Enter level :";
    cin>>k;
    KthLevelOfTree(root,k);
    
    return 0;
}