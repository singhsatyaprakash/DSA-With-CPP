#include <iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> levelOrder(Node *root) {
    if (root == nullptr)
        return {};

    queue<Node *> q;
    vector<vector<int>> res;

    q.push(root);
    int currLevel = 0;

    while (!q.empty()) {
        int len = q.size();
        res.push_back({});

        for (int i = 0; i < len; i++) {

            Node *node = q.front();
            q.pop();

            res[currLevel].push_back(node->data);

            if (node->left != nullptr)
                q.push(node->left);

            if (node->right != nullptr)
                q.push(node->right);
        }
        currLevel++;
    }
    return res;
}
