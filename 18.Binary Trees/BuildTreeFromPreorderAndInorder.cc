#include<iostream>
#include<vector>
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

int top = 0;
TreeNode* helper(int idx, int n, vector<int>& preorder, vector<int>& inorder){
    if(idx >= n) return nullptr;

    TreeNode* root = new TreeNode(preorder[top++]);

    int pos = idx;
    for(int i = idx; i < n; i++){
        if(inorder[i] == root->data){
            pos = i;
            break;
        }
    }

    root->left  = helper(idx, pos, preorder, inorder);
    root->right = helper(pos+1, n, preorder, inorder);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helper(0, inorder.size(), preorder, inorder);
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

    vector<int> preorder(n), inorder(n);

    cout << "Enter preorder:\n";
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    cout << "Enter inorder:\n";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder of constructed tree:\n";
    printInorder(root);

    return 0;
}
