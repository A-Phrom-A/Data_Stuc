#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* findmin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deletenode(Node* root, int data) {
    if (data > root->data) {
        root->right = deletenode(root->right, data);
    } else if (data < root->data) {
        root->left = deletenode(root->left, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findmin(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }
    return root;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data > root->data) {
        root->right = insert(root->right, data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    return root;
}

void breathfirst(Node* root) {
    if (root == NULL) return; // Handle the case where the tree is empty

    vector<Node*> q; // Using a vector to simulate a queue
    q.push_back(root); // Enqueue the root

    while (!q.empty()) {
        int level = q.size();
        for (int i = 0; i < level; i++) {
            Node* current = q[0]; // Get the front element
            q.erase(q.begin()); // Dequeue the front element

            if (i == level - 1) {
                cout << current->data << ",|";
            } else {
                cout << current->data << ",";
            }

            if (current->left != NULL) {
                q.push_back(current->left); // Enqueue left child
            }
            if (current->right != NULL) {
                q.push_back(current->right); // Enqueue right child
            }
        }
    }
    cout << endl;
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << ",";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << ",";
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << ",";
    }
}

int main() {
    Node* test = NULL;
    char c;
    int data;
    do {
        cin >> c;
        switch (c) {
            case 'a': {
                cin >> data;
                test = insert(test, data);
                break;
            }
            case 'p': {
                preorder(test);
                cout << endl;
                break;
            }
            case 't': {
                postorder(test);
                cout << endl;
                break;
            }
            case 'i': {
                inorder(test);
                cout << endl;
                break;
            }
            case 'b': {
                breathfirst(test);
                break;
            }
            case 'd': {
                cin >> data;
                test = deletenode(test, data);
                break;
            }
        }
    } while (c != 'x');
}

