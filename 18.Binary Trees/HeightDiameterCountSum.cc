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

//height of tree...
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left_height=height(root->left);
    int right_height=height(root->right);
    int total_height=max(left_height,right_height)+1;
    return total_height;
}
int count(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftCount=count(root->left);
    int rightCount=count(root->right);
    int totalCount=leftCount+rightCount+1;
    return totalCount;
}
int sum(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftsum=sum(root->left);
    int rightsum=sum(root->right);
    int totalsum=leftsum+rightsum+root->data;
    return totalsum;
}

int diam1(Node* root){
    if(root==NULL){
        return 0;
    }
    int currDiam=height(root->left)+height(root->right)+1;
    int leftDiam=diam1(root->left);
    int rightDiam=diam1(root->right);
    return max(currDiam,max(leftDiam,rightDiam));
}
pair<int,int> diam2(Node* root){
    if(root==NULL){
        return make_pair(0,0);
    }
    //(diameter,height)
    pair<int,int> leftInfo=diam2(root->left);//LD,LH
    pair<int,int> rightInfo=diam2(root->right);//RD,RH
    int currDiam=leftInfo.second+rightInfo.second+1;
    int finalDiam=max(currDiam,max(leftInfo.first,rightInfo.first));
    int finalHt=max(leftInfo.second,rightInfo.second)+1;
    return make_pair(finalDiam,finalHt);
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=BulidTree(nodes);
    cout<<"Height of tree:"<<height(root)<<endl;
    cout<<"Count of nodes:"<<count(root)<<endl;
    cout<<"Sum of nodes:"<<sum(root)<<endl;
    cout<<"Diameter of tree O(n^2):"<<diam1(root)<<endl;
    cout<<"Diameter of tree O(n):"<<diam2(root).first<<endl;
    return 0;
}