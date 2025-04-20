#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
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

class Tree{

    public:
    Node* root;

    Tree(){
        root = NULL;
    }

    Node* createTree(Node* root){
    
        int data;
        cin >> data;
        root = new Node(data);

        if (data==-1){
            return NULL;
        }
        
        root->left = createTree(root->left);
        root->right = createTree(root->right);

        return root;
    }

    void printTree(Node* root){

        if (root==NULL){
            return;
        }

        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
        return;
    }
};