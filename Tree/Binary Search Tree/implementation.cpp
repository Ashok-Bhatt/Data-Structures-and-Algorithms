#include <iostream>
#include <queue>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree{

    public:
    Node* root;

    Tree(){
        root = NULL;
    }

    void insert(Node* &root, int value){
        if (root==NULL){
            root =  new Node(value);
        }
        else if (value > root->data){
            if (root->right!=NULL){
                insert(root->right, value);
            }
            else{
                root->right = new Node(value);
            }
        }
        else{
            if (root->left!=NULL){
                insert(root->left, value);
            }
            else{
                root->left = new Node(value);
            }
        }
    }

    void inOrder(Node* root){

        if (root==NULL){
            return;
        }

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
        return;
    }

    void preOrder(Node* root){

        if (root==NULL){
            return;
        }

        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
        return;
    }

    void postOrder(Node* root){

        if (root==NULL){
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
        return;
    }

    bool search(Node* root, int value){

        while (root!=NULL){
            if (root->data==value){
                return true;
            }
            else if (value>root->data){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }

        return false;
    }

};

int main(){
    
    Tree* t1 = new Tree();
    int data = 1;

    cout << "Enter the data values of tree nodes: " ;
    while (data!=-1){
        cin >> data;
        t1->insert(t1->root, data);
    }
    cout << endl;

    cout << endl << "Inorder Traversal: " << endl;
    t1->inOrder(t1->root);

    cout << endl << "Preorder Traversal: " << endl;
    t1->preOrder(t1->root);

    cout << endl << "Postorder Traversal: " << endl;
    t1->postOrder(t1->root);

    cout << endl << "Searching for -1: " << t1->search(t1->root, -1) << endl;
    cout << "Searching for 2: " << t1->search(t1->root, 2) << endl;
    cout << "Searching for 1: " << t1->search(t1->root, 1) << endl;
    cout << "Searching for 4: " << t1->search(t1->root, 4) << endl;
    cout << "Searching for 3: " << t1->search(t1->root, 3) << endl;
}