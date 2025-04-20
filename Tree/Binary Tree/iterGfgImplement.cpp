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

    stack<Node*> s;
    Node* temp = root;

    while (!s.empty() || temp!=NULL){

        while (temp!=NULL){
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        cout << temp->data << " ";
        s.pop();
        temp = temp->right;

    }

}

void preOrder(Node* root){

    stack<Node*> s;
    Node* temp = root;

    while (!s.empty() || temp!=NULL){

        while (temp!=NULL){
            cout << temp->data << " ";
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();
        temp = temp->right;

    }

}

void postOrder(Node* root){

    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);
    while (!s1.empty()){
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left!=NULL){
            s1.push(temp->left);
        }
        if (temp->right!=NULL){
            s1.push(temp->right);
        }
    }

    while (!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
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