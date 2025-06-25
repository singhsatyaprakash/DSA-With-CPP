/* Problem Statement 35:Design an algorithm and a program to convert binary search tree created in previous question into balanced BST. Also find maximum and minimum element from this balanced BST.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdlib.h>
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
int FindSize(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int leftSize=FindSize(root->left);
    int rightSize=FindSize(root->right);
    return leftSize+rightSize+1;
}
void getinorder(TreeNode* root,int arr[]){
    if(root==NULL){
        return;
    }
    static int i=0;
    getinorder(root->left,arr);
    arr[i++]=root->data;
    getinorder(root->right,arr);
}
TreeNode* BSTtoBalance(int arr[],int si,int ei){
    if(si>ei){
        return NULL;
    }
    int mid=si+(ei-si)/2;
    TreeNode* curr=CreateNode(arr[mid]);
    curr->left=BSTtoBalance(arr,si,mid-1);
    curr->right=BSTtoBalance(arr,mid+1,ei);
    return curr;
}
void PrintPreOrder(TreeNode* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    PrintPreOrder(root->left);
    PrintPreOrder(root->right);
}
int getmin(TreeNode* root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL){
        return root->data;
    }
    
    return getmin(root->left);
}
int getmax(TreeNode* root){

    if(root==NULL || root->right==NULL){
        return root->data;
    }
    return getmax(root->right);
}
int main(){
    TreeNode* root=NULL;
    int key;
    printf("Press [1] to CreateTree.\n");
    printf("Press [2] to InsertNode.\n");
    printf("Press [3] to convert into Balanced Binary Tree.\n");
    printf("Press [4] to PrintTree.\n");
    printf("Press [5] to Find Minimun.\n");
    printf("Press [6] to Find Maximum.\n");
    printf("Press [0] to Exit.\n");
    int choice;
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
                int n=FindSize(root);
                int arr[n];
                getinorder(root,arr);
                TreeNode* balancedroot=BSTtoBalance(arr,0,n-1);
                printf("Balanced Tree:");
                PrintPreOrder(balancedroot);
                printf("\n");
                break;
            }
            case 4:{
                printf("Tree:");
                PrintPreOrder(root);
                printf("\n");
                break;
            }
            case 5:{
                printf("Minimum element is:%d\n",getmin(root));
                break;
            }
            case 6:{
                printf("Maximum element is:%d\n",getmax(root));
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
