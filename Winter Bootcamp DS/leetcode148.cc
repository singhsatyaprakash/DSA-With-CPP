#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    //Spliting the linked list...
    ListNode* MidOfList(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;//to track the mid point and split it...
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
        prev->next=NULL;//spilt done...
        }
        return slow;//right head..
    }

    //mergeing sorted list...
    ListNode* mergelist(ListNode* left,ListNode* right){
        ListNode* dummy= new ListNode();
        ListNode* tail=dummy;
        while(left!=nullptr && right!=nullptr){
            if(left->val<right->val){
                tail->next=left;
                tail=left;
                left=left->next;
            }
            else{
                tail->next=right;
                tail=right;
                right=right->next;
            }
        }
        while(left!=nullptr){
            tail->next=left;
            tail=left;
            left=left->next;
        }
        while(right!=nullptr){
            tail->next=right;
            tail=right;
            right=right->next;
        }
        ListNode *res=dummy->next;
        delete(dummy);
        return res;
    }
    
    //merge sort function...
    ListNode* sortList(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* righthead=MidOfList(head);
        head=sortList(head);//call to sort left half
        righthead=sortList(righthead);//call to sort right half
        return mergelist(head,righthead);
    }    
};
void printlist(ListNode* head){
    while(head!=nullptr){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}
int main(){
    Solution s;
    ListNode* head=new ListNode(5);
    head->next=new ListNode(3);
    head->next->next= new ListNode(1);
    head->next->next->next= new ListNode(2);
    cout<<"Unsorted list:"<<endl;
    printlist(head);
    head=s.sortList(head);
    cout<<"Sorted list:"<<endl;
    printlist(head);
    return 0;
}