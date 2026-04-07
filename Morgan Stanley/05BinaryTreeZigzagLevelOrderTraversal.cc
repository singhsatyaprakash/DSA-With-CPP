#include<bits/stdc++.h>
using namespace std;
//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution1 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        deque<TreeNode*> dq;
        dq.push_back(root);
        bool reverse = false;

        while (!dq.empty()) {
            int size = dq.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                if (!reverse) {
                    TreeNode* node = dq.front(); dq.pop_front();
                    level.push_back(node->val);
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } else {
                    TreeNode* node = dq.back(); dq.pop_back();
                    level.push_back(node->val);
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
            }

            res.push_back(level);
            reverse = !reverse;
        }

        return res;
    }
};


class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>>ans;
        int depth=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            while(size--){
                auto node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
            if(depth%2!=0){
                reverse(temp.begin(),temp.end());
            }
            depth++;
            ans.push_back(temp);
        }
        return ans;
    }
};