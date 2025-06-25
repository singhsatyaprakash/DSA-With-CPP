#include<iostream>
using namespace std;
struct node{
    int cons;
    int pow;
    struct node* next;
};
typedef struct node node;
void display(node* head){
    while(head!=NULL){
        cout<<head->cons<<"x^"<<head->pow<<"+";
        head=head->next;
    }
    cout<<endl;
}
void insert(node **head,node** last,int a,int b){//a==cons  b==pow
    node* newnode=(node*)malloc(sizeof(node));
    newnode->cons=a;
    newnode->pow=b;
    newnode->next=NULL;
    if(*head==NULL){
        *head=*last=newnode;
    }
    else{
        (*last)->next=newnode;
        *last=newnode;
    }
}
node* computeSum(node* list1,node* list2){
    node* head3=NULL;
    node* last3=NULL;
    while(list1!=NULL && list2!=NULL){
        if(list1->pow > list2->pow){
            insert(&head3,&last3,list1->cons,list1->pow);
            list1=list1->next;
        }
        else if(list1->pow < list2->pow){
            insert(&head3,&last3,list2->cons,list2->pow);
            list2=list2->next;
        }
        else{
            insert(&head3,&last3,list2->cons+list1->cons,list1->pow);
            list1=list1->next;
            list2=list2->next;
        }
    }
    while(list1!=NULL){
            insert(&head3,&last3,list1->cons,list1->pow);
            list1=list1->next;
    }
    while(list2!=NULL){
            insert(&head3,&last3,list2->cons,list2->pow);
            list2=list2->next;
    }
    cout<<"Added list:"<<endl;
    display(head3);
    
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    node* last1=NULL;
    node* last2=NULL;
    ///creating list 1
    insert(&head1,&last1,3,3);
    insert(&head1,&last1,2,2);
    insert(&head1,&last1,1,1);
    insert(&head1,&last1,-4,0);
    cout<<"List 1:"<<endl;
    display(head1);
    //creating list 2
    insert(&head2,&last2,2,2);
    insert(&head2,&last2,3,1);
    insert(&head2,&last2,1,0);
    cout<<"List 2:"<<endl;
    display(head2);
    computeSum(head1,head2);
    return 0;
}
