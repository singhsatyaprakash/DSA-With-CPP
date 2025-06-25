/* Problem Statement 33:For an expression in the form of binary tree, infix representation of the expression is given in the form of character array.Design an algorithm and a program to convert infix expression of this tree to postfix expression.Postfix representation of expression should follow BODMAS rule.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree_type{
    char data;
    struct tree_type *right,*left;
}tree_type;
tree_type *createNode(char ch){
    tree_type* temp=(tree_type*)malloc(sizeof(tree_type));
    temp->data=ch;
    temp->left=temp->right=NULL;
    return temp;
}
int precedence(char ch){
    switch(ch){
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
        case '^':return 3;
        case '(':return 0;
    }
}
typedef struct stackNums{
    int top,size;
    tree_type **array;
}stackNums;
typedef struct stackOper{
    int top,size;
    char *array;
}stackOper;
stackNums *initialzeNums(int n){
    stackNums* temp=(stackNums*)malloc(sizeof(stackNums));
    temp->top=-1;
    temp->size=n;
    temp->array=(tree_type**)malloc(sizeof(tree_type)*n);
    return temp;
}
stackOper *initialzeOper(int n){
    stackOper* temp=(stackOper*)malloc(sizeof(stackOper));
    temp->size=n;
    temp->top=-1;
    temp->array=(char*)malloc(sizeof(char)*n);
    return temp;
}
void pushNums(stackNums *st,tree_type *val){
    st->array[++(st->top)]=val;
}
void pushOper(stackOper *st,char ch){
    st->array[++(st->top)]=ch;
}
tree_type *popNums(stackNums *st){
    return st->array[(st->top)--];
}
char popOper(stackOper *st){
    return st->array[(st->top)--];
}
void postOrder(tree_type *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%c",root->data);
    }
}
int main(){
    char str[100];
    tree_type *root=NULL;
    printf("Enter the prefix expression:");
    scanf("%[^\n]s",str);
    stackNums *nums=initialzeNums(strlen(str));
    stackOper *oper=initialzeOper(strlen(str));
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='('){
            pushOper(oper,str[i]);
        }else if(str[i]==')'){
            char ch=popOper(oper);
            while(ch!='('){
                tree_type *b=popNums(nums);
                tree_type *a=popNums(nums);
                root=createNode(ch);
                root->left=a;
                root->right=b;
                pushNums(nums,root);
                ch=popOper(oper);
            }
        }else if(str[i]>='a' && str[i]<='z'){
            pushNums(nums,createNode(str[i]));
        }else{
            if(oper->top==-1)
                pushOper(oper,str[i]);
            else{
                while(oper->top!=-1 && precedence(str[i])<=precedence(oper->array[oper->top])){
                    root =createNode(popOper(oper));
                    tree_type *b=popNums(nums);
                    tree_type *a=popNums(nums);
                    root->left=a;
                    root->right=b;
                    pushNums(nums,root);
                }
                pushOper(oper,str[i]);
            }
        }
    }
    while((oper->top)!=-1){
        root =createNode(popOper(oper));
        tree_type *b=popNums(nums);
        tree_type *a=popNums(nums);
        root->left=a;
        root->right=b;
        pushNums(nums,root);
    }
    root=nums->array[nums->top];
    printf("PostFix expression:");
    postOrder(root);
    return 0;
}