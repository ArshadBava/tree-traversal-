#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Postorder traversal (Left, Right, Root)
void printPostorder(Node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

// Inorder traversal (Left, Root, Right)
void printInorder(Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// Preorder traversal (Root, Left, Right)
void printPreorder(Node* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n;
    cout << "Enter how many nodes you want to create: ";
    cin >> n;

    int node_values[n];

    cout << "Enter the root node value: ";
    int root_node_value;
    cin >> root_node_value;
    Node* root = new Node(root_node_value);

    queue<Node*> nodeQueue;
    nodeQueue.push(root);

    int valueIndex = 0;
    while (!nodeQueue.empty() && valueIndex < n) {
        Node* currentNode = nodeQueue.front();
        nodeQueue.pop();

        if (currentNode->data != root_node_value) {
            cout << "Enter " << currentNode->data << " -> left node value: ";
            cin >> node_values[valueIndex];
            currentNode->left = new Node(node_values[valueIndex]);
            nodeQueue.push(currentNode->left);
            valueIndex++;

            cout << "Enter " << currentNode->data << " -> right node value: ";
            cin >> node_values[valueIndex];
            currentNode->right = new Node(node_values[valueIndex]);
            nodeQueue.push(currentNode->right);
            valueIndex++;
        } else {
            cout << "Enter root -> left node value: ";
            cin >> node_values[valueIndex];
            currentNode->left = new Node(node_values[valueIndex]);
            nodeQueue.push(currentNode->left);
            valueIndex++;

            cout << "Enter root -> right node value: ";
            cin >> node_values[valueIndex];
            currentNode->right = new Node(node_values[valueIndex]);
            nodeQueue.push(currentNode->right);
            valueIndex++;
        }
    }

    cout << "\nPreorder traversal of binary tree is: \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is: \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is: \n";
    printPostorder(root);
    cout << endl;

    return 0;
}
