#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        this->root = nullptr;
    }

    void inOrder(Node* root) {
        if (root == nullptr) {
            return;
        }

        inOrder(root->left);
        cout << root->data << endl;
        inOrder(root->right);
    }

    Node* insert(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }

        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }

    void inOrderTraversal() {
        inOrder(this->root);
    }

    void insertNode(int val) {
        this->root = insert(this->root, val);
    }
};

int main() {
    BST* b1 = new BST();
    int val, node;

    cout << "Enter the number of nodes: ";
    cin >> node;

    for (int i = 1; i <= node; i++) {
        cout << "Enter the value of node " << i << " : ";
        cin >> val;
        b1->insertNode(val);
    }

    cout << endl << "Inorder Traversal: " << endl;
    b1->inOrderTraversal();
}
