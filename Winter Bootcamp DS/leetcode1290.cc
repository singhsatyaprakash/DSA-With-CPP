#include<iostream>
#include<math.h>
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
    int getDecimalValue(ListNode* head) {
        int sum=0;
        int n=0;//length of linkedList..
        ListNode* temp=head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        while(head!=nullptr){
            sum+=pow(2.0,n-1)*(head->val);
            head=head->next;
            n--;
        }
        return sum;
    }
};
int main(){
    Solution s;
    ListNode* head=new ListNode(1);
    head->next=new ListNode(0);
    head->next->next=new ListNode(0);
    cout<<"Integer value is:"<<s.getDecimalValue(head);
    return 0;
}