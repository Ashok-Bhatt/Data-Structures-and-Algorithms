#include <iostream>
#include "tree.cpp"
using namespace std;

int findNo(Node* root){

    if (root->left==NULL && root->right==NULL){
        return 1;
    }

    int leftSide = 0;
    int rightSide = 0;
    if (root->left){
        leftSide = findNo(root->left);
    }
    if (root->right){
        rightSide = findNo(root->right);
    }

    return leftSide+rightSide;

}

int main(){

    Tree* t1 = new Tree();
    cout << "Enter the tree Nodes: ";
    t1->root = t1->createTree(t1->root);

    cout << "Printed Tree: ";
    t1->printTree(t1->root);

    int ans = findNo(t1->root);
    cout << endl << "No. of leaf nodes: " << ans;
}