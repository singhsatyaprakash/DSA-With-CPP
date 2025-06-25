/*.Given a binary search tree, design an algorithm and write a program to find which level number of tree has maximum number of nodes. Also print maximum number of nodes present at this level.
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
void levelHaveMaxNode(TreeNode* root) {
    if(root==NULL){
        printf("The tree is empty.\n");
        return;
    }
    TreeNode* queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    int level=0,maxNodes=0,maxLevel=0; 
    while(front!=rear){
        int levelSize=rear - front; //size of queue equal to number of element at that level...
        if(levelSize > maxNodes){
            maxNodes= levelSize;
            maxLevel= level;
        }
        for(int i=0;i<levelSize;i++){
            TreeNode* current=queue[front++];
            if(current->left!=NULL){
                queue[rear++] = current->left;
            }
            if(current->right!=NULL){
                queue[rear++] = current->right;
            }
        }
        level++;
    }
    printf("Level with maximum nodes: %d,Number of nodes: %d\n",maxLevel,maxNodes);
}
void PrintInorder(TreeNode* root) {
    if(root==NULL){
        return;
    }
    PrintInorder(root->left);
    printf("%d ", root->data);
    PrintInorder(root->right);
}
int main(){
    TreeNode* root=NULL;
    printf("Press[1] for CreateNode.\nPress[2] for InsertNode.\nPress[3] for PrintTree.\nPress[4] for Level having Max Nodes.\nPress[0] for Exit.\n");
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
                printf("Tree:");
                PrintInorder(root);
                printf("\n");
                break;
            }
            case 4:{
                levelHaveMaxNode(root);
                break;
            }
            case 0:{
                printf("Exit.\n");
                break;
            }
            default:
            printf("Invalid choice.\n");
        }
    }while(choice!=0);
    return 0;
}