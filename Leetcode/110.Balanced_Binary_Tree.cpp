#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    if (l == -1 || r == -1 || abs(l - r) > 1) {
        return -1;
    }
    return std::max(l, r) + 1;
}


bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
        return false;
    }
    if (height(root) == -1) return false;
    return true;
}


int main() {
    TreeNode *tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    std::cout << isBalanced(tree);
}