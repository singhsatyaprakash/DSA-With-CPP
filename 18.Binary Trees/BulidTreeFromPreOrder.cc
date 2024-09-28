#include<iostream>
#include<vector>
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
void preOrder(Node* root){
    if(root==NULL){
        cout<<-1<<" ";//no further node...
        return;
    }
    //root..
    cout<<root->data<<" ";
    //left..
    preOrder(root->left);
    //right..
    preOrder(root->right);
    return;
}
void InOrder(Node* root){
    if(root==NULL){
        cout<<-1<<" ";//no further node...
        return;
    }
    //left..
    InOrder(root->left);
    //root..
    cout<<root->data<<" ";
    //right..
    InOrder(root->right);
    return;
}
void PostOrder(Node* root){
    if(root==NULL){
        cout<<-1<<" ";//no further node...
        return;
    }
    //left..
    PostOrder(root->left);
    //right..
    PostOrder(root->right);
    //root..
    cout<<root->data<<" ";
    return;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    //Buliding Tree...
    Node* root=BulidTree(nodes);

    //Preorder Travesal...(root,left,right)...
    cout<<"\nPreorder Traversal: "<<endl;
    preOrder(root);

    //Inorder Travesal...(left,root,right)...
    cout<<"\nInorder Traversal: "<<endl;
    InOrder(root);

    //Postorder Travesal...(left,right,root)...
    cout<<"\nPostorder Traversal: "<<endl;
    PostOrder(root);

    return 0;
}