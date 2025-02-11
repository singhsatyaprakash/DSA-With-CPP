#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* temp = nullptr;

    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (head == nullptr) {
            head = new ListNode(val);
            temp = head;
        } else {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }
    return head;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    unordered_set<ListNode*> visited;

    while (headA != nullptr) {
        visited.insert(headA);
        headA = headA->next;
    }

    while (headB != nullptr) {
        if (visited.find(headB) != visited.end()) {
            return headB;
        }
        headB = headB->next;
    }

    return nullptr;
}

int main() {
    int n1, n2, commonLength;
    cout << "Enter the number of nodes in the first linked list: ";
    cin >> n1;
    ListNode* headA = createList(n1);

    cout << "Enter the number of nodes in the second linked list: ";
    cin >> n2;
    ListNode* headB = createList(n2);

    cout << "Enter the number of common nodes (intersection): ";
    cin >> commonLength;
    ListNode* commonHead = nullptr;
    if (commonLength > 0) {
        cout << "Enter the common node values: ";
        commonHead = createList(commonLength);

        // Attach the common list to the end of both lists
        ListNode* temp = headA;
        while (temp && temp->next) {
            temp = temp->next;
        }
        if (temp) temp->next = commonHead;

        temp = headB;
        while (temp && temp->next) {
            temp = temp->next;
        }
        if (temp) temp->next = commonHead;
    }

    ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection." << endl;
    }

    return 0;
}
