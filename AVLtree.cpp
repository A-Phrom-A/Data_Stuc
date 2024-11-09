#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(NULL), right(NULL), height(1) {}
};

// AVL Tree class
class AVLTree {
private:
    Node* root;

    // Helper function to get the height of the node
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Helper function to get the balance factor of the node
    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Right rotate utility
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    // Left rotate utility
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Insert a node into the AVL Tree
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else // Duplicate keys are not allowed
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Balance the node if needed
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Helper function to find the minimum value node
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left) current = current->left;
        return current;
    }

    // Delete a node from the AVL Tree
    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;

            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }

        if (!root) return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Pre-order traversal of the AVL Tree
    void preOrder(Node* root) {
        if (root) {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

public:
    AVLTree() : root(NULL) {}

    void add(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    void printPreOrder() {
        preOrder(root);
        cout << endl;
    }
};

// Main function to interact with the AVL Tree
int main() {
    AVLTree tree;
    char command;
    int value;

    while (true) {
        cin >> command;
        switch (command) {
            case 'a':
                cin >> value;
                tree.add(value);
                break;
            case 'd':
                cin >> value;
                tree.remove(value);
                break;
            case 'p':
                tree.printPreOrder();
                break;
            case 'x':
                return 0;
            default:
                cerr << "Invalid command!" << endl;
                break;
        }
    }

    return 0;
}

