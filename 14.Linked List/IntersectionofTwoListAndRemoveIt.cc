/*Intersection of Two Linked Lists
In a system there are two singly linked list. By some programming error, the end node of one of the linked lists got linked to the second list, forming an inverted Y-shaped list. Write a program to get the point where two linked lists merge.
We have to find the intersection part in this system.*/
#include <iostream>
using namespace std;

// Define the structure for a linked list node
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to get the length of the linked list
int getLength(ListNode* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the intersection point of two linked lists
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // Get the lengths of both linked lists
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    
    // Align the starting points of both lists
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }
    
    // Traverse both lists and find the intersection point
    while (headA != nullptr && headB != nullptr) {
        if (headA == headB) {
            return headA;  // Intersection point found
        }
        headA = headA->next;
        headB = headB->next;
    }
    
    return nullptr;  // No intersection
}

// Test the function
int main() {
    // Create two linked lists
    ListNode* newNode;
    
    // List A: 10 -> 20 -> 30
    ListNode* headA = new ListNode(10);
    headA->next = new ListNode(20);
    headA->next->next = new ListNode(30);
    
    // List B: 5 -> 15
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(15);
    
    // Merge both lists at node 30 (intersection)
    newNode = new ListNode(40);
    headA->next->next->next = newNode;
    headB->next->next = newNode;
    
    newNode->next = new ListNode(50);  // Common part of the list
    newNode->next->next = nullptr;
    
    // Find the intersection point
    ListNode* intersection = getIntersectionNode(headA, headB);
    
    if (intersection != nullptr) {
        cout << "Intersection at node with data: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    
    return 0;
}
