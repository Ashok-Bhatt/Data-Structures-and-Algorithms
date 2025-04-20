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

Node* createTree(Node* root){
    
    int data;
    cin >> data;
    root = new Node(data);

    if (data==-1){
        return NULL;
    }
    
    cout << "Enter the left node value for " << root->data << ": ";
    root->left = createTree(root->left);
    cout << "Enter the right node value for " << root->data << ": ";
    root->right = createTree(root->right);

    return root;
}

void levelOrder(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){

        Node* temp = q.front();
        q.pop();

        if (temp==NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if (temp->left!=NULL){
                q.push(temp->left);
            }
            if (temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }

}

void inOrder(Node* root){

    unordered_map<Node*, int> mapping;
    stack<Node*> s;
    
    s.push(root);

    while (!s.empty()){    
        Node* temp = s.top();
        if (temp==NULL){
            s.pop();
        }
        else if (mapping[temp]==0){
            mapping[temp]++;
            s.push(temp->left);
        }
        else if (mapping[temp]==1){
            cout << temp->data << " ";
            mapping[temp]++;
            s.push(temp->right);
        }
        else{
            s.pop();
        }
    }

}

void preOrder(Node* root){

    unordered_map<Node*, int> mapping;
    stack<Node*> s;
    
    s.push(root);

    while (!s.empty()){    
        Node* temp = s.top();
        if (temp==NULL){
            s.pop();
        }
        else if (mapping[temp]==0){
            cout << temp->data << " ";
            mapping[temp]++;
            s.push(temp->left);
        }
        else if (mapping[temp]==1){
            mapping[temp]++;
            s.push(temp->right);
        }
        else{
            s.pop();
        }
    }
}

void postOrder(Node* root){

    unordered_map<Node*, int> mapping;
    stack<Node*> s;
    
    s.push(root);

    while (!s.empty()){    
        Node* temp = s.top();
        if (temp==NULL){
            s.pop();
        }
        else if (mapping[temp]==0){
            mapping[temp]++;
            s.push(temp->left);
        }
        else if (mapping[temp]==1){
            mapping[temp]++;
            s.push(temp->right);
        }
        else{
            cout << temp->data << " ";
            s.pop();
        }
    }
}

int main() {

    Node* root = NULL;
    /* 3 4 6 -1 -1 7 -1 -1 5 8 -1 -1 9 -1 -1 */
    cout << "Enter the value of root node: ";
    root = createTree(root);

    cout << endl << "Level Order Tarversal of a tree: " << endl;
    levelOrder(root);

    cout << endl << "In Order Tarversal of a tree: " << endl;
    inOrder(root);

    cout << endl << "Pre Order Tarversal of a tree: " << endl;
    preOrder(root);

    cout << endl << "Post Order Tarversal of a tree: " << endl;
    postOrder(root);
}