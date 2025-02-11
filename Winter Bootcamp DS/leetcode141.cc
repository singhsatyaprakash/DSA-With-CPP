#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
bool hasCycle(ListNode *head) {
       ListNode* fast=head;
       ListNode* slow=head;
       while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
              return true; 
       }
       return false;
       } 

int main() {
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = nullptr;
    ListNode* temp = nullptr;

    cout << "Enter node values: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        if (head == nullptr) {
            head = new ListNode(val);
            temp = head;
        } else {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }

    if (n > 1) temp->next = head;

    cout << "Has cycle: " << (hasCycle(head) ? "Yes" : "No") << endl;
    return 0;
}
