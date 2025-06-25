/* Problem Statement 34:Design an algorithm and a program to implement binary search tree. The program should implement following BST operations:
 a) Create() - creates a root node.
 b) Insert() - insert a node in tree.
 c) Delete() - delete a node from tree.
 d) FindHeight() - return height of tree.
 e) FindDepth() - return depth of tree.
 f) Search() - search whether given key is present in tree or not.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
typedef struct node{
    int data;
    struct node *left,*right;
}TreeNode;
TreeNode* CreateNode(int key){
    TreeNode* newnode=(TreeNode*)malloc(sizeof(TreeNode));
    newnode->data=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void InsertNode(TreeNode** root,int key){
    if(*root==NULL){
        *root=CreateNode(key);
        return;
    }
    if(key<(*root)->data){
        InsertNode(&(*root)->left,key);
    }
    else{
        InsertNode(&(*root)->right,key);
    }
}
TreeNode* getSucessor(TreeNode* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
TreeNode* DeleteNode(TreeNode* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){
        root->left=DeleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=DeleteNode(root->right,key);
    }
    else{ //when key==root->data
        //if node to be delete is leaf node
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        //if node to delete have one child
        if(root->left==NULL || root->right==NULL){
            return root->left==NULL?root->right:root->left;
        }
        //if node to be delete have to child
        TreeNode* sucess=getSucessor(root->right);
        root->data=sucess->data;
        root->right=DeleteNode(root->right,sucess->data);
    }
    return root;
} 
int FindHeight(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int leftht=FindHeight(root->left);
    int rightht=FindHeight(root->right);
    int finalht=fmax(leftht,rightht)+1;
    return finalht;
}
int FindSize(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int leftSize=FindSize(root->left);
    int rightSize=FindSize(root->right);
    return leftSize+rightSize+1;
}
bool searchNode(TreeNode* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    bool isInLeft=searchNode(root->left,key);
    if(!isInLeft){//not in left
        return searchNode(root->right,key);
    }
    else{
        return true;
    }
}
void PrintInorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    PrintInorder(root->left);
    printf("%d ",root->data);
    PrintInorder(root->right);
}
int main(){
    TreeNode* root=NULL;
    printf("Press [1] to CreateTree.\n");
    printf("Press [2] to InsertNode.\n");
    printf("Press [3] to DeleteNode.\n");
    printf("Press [4] to FindHeight.\n");
    printf("Press [5] to FindSize.\n");
    printf("Press [6] to Search.\n");
    printf("Press [7] to PrintTree(Inorder).\n");
    printf("Press [0] to Exit.\n");
    int choice,key;
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter root key:");
                scanf("%d",&key);
                root=CreateNode(key);
                break;
            }
            case 2:{
                printf("Enter root key:");
                scanf("%d",&key);
                InsertNode(&root,key);
                break;
            }
            case 3:{
                printf("Enter root key:");
                scanf("%d",&key);
                root=DeleteNode(root,key);
                break;
            }
            case 4:{
                int ht=FindHeight(root);
                printf("Height of tree is:%d\n",ht);
                break;
            }
            case 5:{
                int size=FindSize(root);
                printf("Size of tree is:%d\n",size);
                break;
            }
            case 6:{
                int key;
                printf("Enter key to search:");
                scanf("%d",&key);
                if(searchNode(root,key)){
                    printf("Key is present.\n");
                }
                else{
                    printf("Key not present.\n");
                }
                break;
            }
            case 7:{
                printf("Tree:");
                PrintInorder(root);
                printf("\n");
                break;
            }
            case 0:{
                printf("Exit.\n");
                break;
            }
            default:
                printf("Invalid Option.\n");
        }
    }while(choice!=0);
return 0;
}