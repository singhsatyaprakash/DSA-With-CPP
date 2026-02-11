#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int top;  

TreeNode* helper(int start, int end,vector<int>& postorder,vector<int>& inorder){

    if (start > end) return NULL;

    TreeNode* root = new TreeNode(postorder[top--]);

    int pos = start;
    for (int i = start; i <= end; i++) {
        if (inorder[i] == root->data) {
            pos = i;
            break;
        }
    }

    root->right = helper(pos + 1, end, postorder, inorder);
    root->left  = helper(start, pos - 1, postorder, inorder);

    return root;
}

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
    top = postorder.size() - 1;
    return helper(0, inorder.size() - 1, postorder, inorder);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> postorder(n), inorder(n);

    cout << "Enter postorder:\n";
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    cout << "Enter inorder:\n";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    TreeNode* root = buildTree(postorder, inorder);

    cout << "Inorder of constructed tree:\n";
    printInorder(root);

    return 0;
}
