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
bool findpath(Node* root,int n,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    //if not hope in subroot..
    int isInLeftSide=findpath(root->left,n,path);
    int isInRightSide=findpath(root->right,n,path);
    if(isInLeftSide || isInRightSide){//dono me se kisi me bhi mil gaya tho...
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(Node* root,int n1,int n2){
    vector<int>path1;
    vector<int>path2;
    findpath(root,n1,path1);
    findpath(root,n2,path2);

    int lca=-1; //means not found...
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i]!=path2[j]){
            return lca;
        }
        lca=path1[i];
    }
    return lca;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root=BulidTree(nodes);
    int n1=4,n2=5;
    cout<<LCA(root,n1,n2);

    return 0;
}