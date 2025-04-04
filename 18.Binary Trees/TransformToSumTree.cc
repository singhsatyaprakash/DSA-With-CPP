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
void LevelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);//to point next line and level...
    while(!Q.empty()){
        Node* curr=Q.front();
        Q.pop();
        if(curr==NULL){
            cout<<endl;
            if(Q.empty()){
                break;
            }
            Q.push(NULL);
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
                Q.push(curr->left);
            }
            if(curr->right!=NULL){
                Q.push(curr->right);
            }
        }
    }
}
int tranform(Node* root){
    if(root==NULL){
        return 0;
    }
    int currOld=root->data;
    int leftOld=tranform(root->left);
    int rightOld=tranform(root->right);
    //modifying..
    root->data=leftOld+rightOld;
    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
    return currOld;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root=BulidTree(nodes);
    LevelOrderTraversal(root);
    tranform(root);
    cout<<"After Tranform:"<<endl;
    LevelOrderTraversal(root);
    return 0;
}