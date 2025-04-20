#include <iostream>
#include <stack>
#include "tree.cpp"
using namespace std;

void reverseOrder(Node* root){
    
    queue<Node*> q1;
    stack<Node*> s1;
    q1.push(NULL);
    q1.push(root);

    while (!q1.empty()){
        Node* temp = q1.front();
        q1.pop();
        s1.push(temp);

        if (temp!=NULL){
            if (temp->left!=NULL){
                q1.push(temp->left);
            }
            if (temp->right!=NULL){
                q1.push(temp->right);
            }
        }
        else{
            if (!q1.empty()){
                q1.push(NULL);
            }
        }
    }

    stack<Node*> ans;
    while (!s1.empty()){

        Node* temp = s1.top();
        s1.pop();
        ans.push(temp);

        if (temp==NULL){
            while (!ans.empty()){
                if (ans.top()==NULL){
                    cout << endl;
                }
                else{
                    cout << ans.top()->data << " ";
                }
                ans.pop();
            }
        }
    }

}

int main(){

    // 3 4 6 -1 -1 7 -1 -1 5 8 -1 -1 9 -1 -1
    Tree* t1 = new Tree();
    cout << "Enter the tree Nodes: ";
    t1->root = t1->createTree(t1->root);

    cout << "Printed Tree: ";
    t1->printTree(t1->root);

    cout << endl << "Reversed Order Traversal: ";
    reverseOrder(t1->root);
}