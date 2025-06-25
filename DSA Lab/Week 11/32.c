/*Problem Statement 32:Write an algorithm and a program to implement following types of traversing in the tree:
 a) inorder() - (1) traverse left subtree, (2) traverse root, (3) traverse right subtree
 b) postorder() - (1) traverse root, (2) traverse left subtree, (3) traverse right subtree
 c) preorder() - (1) traverse left subtree, (2) traverse right subtree, (3) traverse root
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
typedef struct TreeNode{
    struct TreeNode* left;
    int data;
    struct TreeNode* right;
}TreeNode;

TreeNode* CreateNode(int val){
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
    root->left=NULL;
    root->data=val;
    root->right=NULL;
    return root;
}
void InsertNode(TreeNode** root,int value){
    TreeNode* queue[100];
    int front=0,rear=0;
    queue[rear]=*root;//insert address of root node..
    rear++;
    while(front!=rear){
        TreeNode* temp=queue[front++];
        if(temp->left==NULL){
            temp->left=CreateNode(value);
            return;
        }
        else{
            queue[rear++]=temp->left;
        }
        if(temp->right==NULL){
            temp->right=CreateNode(value);
            return;
        }
        else{
            queue[rear++]=temp->right;
        }
    }  
}
void PrintPreorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}
void PrintInorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    PrintInorder(root->left);
    printf("%d ",root->data);
    PrintInorder(root->right);
}
void PrintPostorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    PrintPostorder(root->left);
    PrintPostorder(root->right);
    printf("%d ",root->data);
}
int main(){
    TreeNode* root=NULL;
    printf("Press [1] to CreateTree.\n");
    printf("Press [2] to InsertNode.\n");
    printf("Press [3] to PreOrder.\n");
    printf("Press [4] to InOrder.\n");
    printf("Press [5] to PostOrder.\n");
    printf("Press [0] to Exit.\n");
    int choice;
    do{
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int key;
                printf("Enter root key:");
                scanf("%d",&key);
                root=CreateNode(key);
                break;
            }
            case 2:{
                int key;
                printf("Enter key to insert:");
                scanf("%d",&key);
                InsertNode(&root,key);
                break;
            }
            case 3:{
                printf("PreOrder:");
                PrintPreorder(root);
                printf("\n");
                break;
            }
            case 4:{
                printf("Inorder:");
                PrintInorder(root);
                printf("\n");
                break;
            }
            case 5:{
                printf("PostOrder:");
                PrintPostorder(root);
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