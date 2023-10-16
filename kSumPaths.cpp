#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findKSumPaths(TreeNode* root, int k, vector<int>& path, int currentSum) {
    if (root == NULL)
        return;

    path.push_back(root->val);

    int tempSum = 0;
    for (int i = path.size() - 1; i >= 0; i--) {
        tempSum += path[i];
        if (tempSum == k) {
            for (int j = i; j < path.size(); j++) {
                cout << path[j] << " ";
            }
            cout << endl;
        }
    }

    findKSumPaths(root->left, k, path, currentSum);
    findKSumPaths(root->right, k, path, currentSum);

    path.pop_back();
}

void findKSumPaths(TreeNode* root, int k) {
    vector<int> path;
    findKSumPaths(root, k, path, 0);
}

int main() {
    // Construct your binary tree here
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int k = 8;
    findKSumPaths(root, k);

    return 0;
}
