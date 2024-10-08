#include <iostream>
#include <queue>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

void inOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    std::cout << root->value << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    std::cout << root->value << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->value << " ";
}

void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        std::cout << current->value << " ";

        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Level-Order Traversal: ";
    levelOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}

