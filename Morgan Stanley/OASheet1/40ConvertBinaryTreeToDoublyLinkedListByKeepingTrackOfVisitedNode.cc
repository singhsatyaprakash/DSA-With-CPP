#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    Node* bToDLL(Node* root) {
        if (!root) return NULL;

        stack<Node*> st;
        Node* curr = root;
        Node* prev = NULL;
        Node* head = NULL;

        while (curr || !st.empty()) {

            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if (prev == NULL) {
                head = curr;
            } else {
                curr->left = prev;
                prev->right = curr;
            }

            prev = curr;

            curr = curr->right;
        }

        return head;
    }
};