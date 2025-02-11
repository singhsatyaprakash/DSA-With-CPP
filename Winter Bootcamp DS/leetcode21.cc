#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int main() {
    int n1, n2, val;
    cout << "Enter number of nodes in first list: ";
    cin >> n1;
    ListNode* l1 = nullptr;
    ListNode* temp = nullptr;

    cout << "Enter sorted values for first list: ";
    for (int i = 0; i < n1; ++i) {
        cin >> val;
        if (!l1) {
            l1 = new ListNode(val);
            temp = l1;
        } else {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }

    cout << "Enter number of nodes in second list: ";
    cin >> n2;
    ListNode* l2 = nullptr;

    cout << "Enter sorted values for second list: ";
    for (int i = 0; i < n2; ++i) {
        cin >> val;
        if (!l2) {
            l2 = new ListNode(val);
            temp = l2;
        } else {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }

    ListNode* mergedList = mergeTwoLists(l1, l2);

    cout << "Merged list: ";
    while (mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}
