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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
int main(){
    Solution s;
    ListNode* head=NULL;
    int n;
    cout<<""
    int value;
    cin >> value;
    ListNode *head = new ListNode(value); // Create the head node
    ListNode *current = head;

    for (int i = 1; i < n; i++) {
        cin >> value;
        ListNode *newNode = new ListNode(value); // Create a new node
        current->next = newNode; // Link the new node to the current node
        current = newNode;      // Move to the new node
    }
    return 0;
}