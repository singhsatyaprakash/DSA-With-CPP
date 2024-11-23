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

#include<map>
void topView(Node* root){
    queue<pair<Node*,int>>q;//(node,HD)  HD=Horizintal distance...
    map<int,int>m;//(HD,node->data)...
    q.push(make_pair(root,0));
    //level order trasversal...
    while(!q.empty()){
        pair<Node*,int>curr=q.front();
        q.pop();
        Node* currNode=curr.first;
        int currHD=curr.second;
        //chacking uniqueness is it in map or not..
        if(m.count(currHD)==0){//not in mapp add it...
            m[currHD]=currNode->data;
        }
        if(m.count(currHD)){//to repalce top view node with bottom view.
            m[currHD]=currNode->data;
        }

        if(currNode->left!=NULL){
            pair<Node*,int>left=make_pair(currNode->left,currHD-1);
            q.push(left);
        }
        if(currNode->right!=NULL){
            pair<Node*,int>right=make_pair(currNode->right,currHD+1);
            q.push(right);
        }
    }
    //printing map data...
    for(auto it:m){
        cout<<it.second<<" ";
    }
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root=BulidTree(nodes);
    topView(root);
    return 0;
}