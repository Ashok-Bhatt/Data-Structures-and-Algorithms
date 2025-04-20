#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{

    public:
    Node* root;

    BST(){
        this->root = NULL;
    }

    void inOrder(Node* root){
        if (root==NULL){
            return;
        }

        inOrder(root->left);
        cout << root->data << "  ";
        inOrder(root->right);
        return;
    }

    void insert(Node* &root, int val){

        if (root==NULL){
            root = new Node(val);
        } else if (val < root->data){
            if (root->left==NULL){
                root->left = new Node(val);
            } else{
                insert(root->left, val);
            }
        } else{
            if (root->right==NULL){
                root->right = new Node(val);
            } else{
                insert(root->right, val);
            }
        }
    }

    Node* minValueNode(Node* node){

        Node* current = node;
        while (current!=NULL && current->left != NULL)
            current = current->left;
    
        return current;
    }

    Node* deleteNode(Node* root, int val){

        if (root == NULL)
            return root;

        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    void insertNode(int val){
        insert(this->root, val);
    }

    void inOrderTraversal(){
        cout << "Inorder Traversal: ";
        inOrder(this->root);
        cout << endl;
    }

    void deleteNode(int val){
        this->root = deleteNode(this->root, val);
    }
};

int main(){

    BST* b1 = new BST();
    int val, node;

    cout << "Enter the number of nodes: ";
    cin >> node;

    for (int i=1; i<=node; i++){
        cout << "Enter the value of node " << i << " : ";
        cin>> val;
        b1->insertNode(val);
    }

    b1->inOrderTraversal();

    cout << endl << "Enter the node which you want to delete: ";
    cin >> val;
    b1->deleteNode(val);
    b1->inOrderTraversal();
}