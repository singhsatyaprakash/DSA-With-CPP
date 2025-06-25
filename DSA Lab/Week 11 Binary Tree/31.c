#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
typedef struct TreeNode{
    int data;
    struct TreeNode *left,*right;
}TreeNode;
TreeNode* CreateNode(int val){
    if(val==-1){
        return NULL;
    }
    TreeNode* newnode=(TreeNode*)malloc(sizeof(TreeNode));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void InsertNode(TreeNode** root,int key){

}
TreeNode* BulidTree(int arr[],int n){
    TreeNode** newnode=(TreeNode**)malloc(n*sizeof(TreeNode*));
    for(int i=0;i<n;i++){
        newnode[i]=CreateNode(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(newnode[i]!=NULL){
            int leftChild=2*i+1;
            int rightChild=2*i+2;
            if(leftChild<n){
                newnode[i]->left=newnode[leftChild];
            }
            if(rightChild<n){
                newnode[i]->right=newnode[rightChild];
            }
        }
    }
    TreeNode* root=newnode[0];
    return root;
}
void DeleteNode(TreeNode** root,int key){

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
void PrintTree(TreeNode* root){
    if(root==NULL){
        return;
    }
    PrintTree(root->left);
    printf("%d ",root->data);
    PrintTree(root->right);
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
                int n;
                printf("Enter size of array:");
                scanf("%d",&n);
                int arr[n];
                printf("Enter element of array:");
                for(int i=0;i<n;i++){
                    scanf("%d",&arr[i]);
                }
                root=BulidTree(arr,n);
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
                int key;
                printf("Enter key to delete:");
                scanf("%d",&key); 
                DeleteNode(&root,key);
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
                PrintTree(root);
                printf("\n");
                break;
            }
            case 0:{
                printf("Exit.\n");
            }
            default:
                printf("Invalid Option.\n");

        }
    }while(choice!=0);
    return 0;
}