/* Problem Statement 31: Design an algorithm to implement binary trees. Write a program which implements following
 basic operations on binary tree:
 a) CreateTree() - creates a root node
 b) InsertNode() - insert a node in tree
 c) DeleteNode() - delete a node from tree
 d) FindHeight() - find the height of tree
 e) FindSize() - find number of nodes in tree
 f) Search() - search whether given specific element present in tree or not.
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
TreeNode* FoundDelete(TreeNode* root,int key){
    if(root==NULL){
        return NULL;
    }
    TreeNode* inLeft=FoundDelete(root->left,key);
    if(inLeft==NULL){
        return FoundDelete(root->right,key);
    }
    return inLeft;
}
TreeNode* find_Deepest(TreeNode* root){
    TreeNode* queue[100];
    TreeNode* deepest=NULL;
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        TreeNode* temp=queue[front];
        if(temp->left!=NULL){
            queue[rear++]=temp->left;
        }
        if(temp->right!=NULL){
            queue[rear++]=temp->right;
        }
        deepest=queue[front];
        front++;//pop
    }
    return deepest;
}
void deleteDeepestNode(TreeNode* root,TreeNode* deepest){
    TreeNode* queue[100],*curr;
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        curr=queue[front++];
        if(curr->left!=NULL){
            if(curr->left==deepest){
                free(curr->left);
                curr->left=NULL;
                return;
            }else{
                queue[rear++]=curr->left;
            }
        }
        if(curr->right!=NULL){
            if(curr->right==deepest){
                free(curr->right);
                curr->right=NULL;
                return;
            }else{
                queue[rear++]=curr->right;
            }
        }    
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
                if(root==NULL){
                    printf("Tree is empty.Cannot delete.\n");
                    break;
                }
                int key;
                printf("Enter key to delete: ");
                scanf("%d",&key);
                if(searchNode(root,key)){
                    TreeNode* deepest =find_Deepest(root);
                    TreeNode* target =root;
                    TreeNode* queue[100];
                    int front=0,rear=0;
                    queue[rear++]=root;
                    while(front<rear){
                        target=queue[front++];
                        if(target->data==key){
                            target->data=deepest->data;
                            deleteDeepestNode(root,deepest);
                            break;
                        }
                        if(target->left){
                            queue[rear++]=target->left;
                        }
                        if(target->right){
                            queue[rear++] = target->right;
                        }
                    }
                }
                else{
                    printf("Key not found.\n");
                }
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