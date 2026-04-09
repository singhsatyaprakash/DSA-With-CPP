#include<bits/stdc++.h>
using namespace std;
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

class Solution {
  public:
    int getMiddle(Node* head) {
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};