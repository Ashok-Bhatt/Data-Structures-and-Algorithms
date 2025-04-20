#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

struct Node* getNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void inorderTraversal(Node* root, vector<int>& arr)
{
	if (root == NULL)
		return;

	inorderTraversal(root->left, arr);
	arr.push_back(root->data);
	inorderTraversal(root->right, arr);
}

void preorderTraversal(Node* root, vector<int>& arr)
{
	if (!root)
		return;

	arr.push_back(root->data);
	preorderTraversal(root->left, arr);
	preorderTraversal(root->right, arr);
}

void createMinHeap(Node* root, vector<int> &traverse, int &index){

    if (root==NULL){
        return;
    }

    root->data = traverse[index++];
    createMinHeap(root->left, traverse, index);
    createMinHeap(root->right, traverse, index);
}

int main()
{
	struct Node* root = getNode(4);
	root->left = getNode(2);
	root->right = getNode(6);
	root->left->left = getNode(1);
	root->left->right = getNode(3);
	root->right->left = getNode(5);
	root->right->right = getNode(7);

    vector<int> traverse1;
	inorderTraversal(root, traverse1);

    for (int element:traverse1){
        cout << element << " ";
    }
    cout << endl;

    int index = 0;
    createMinHeap(root, traverse1, index);


    vector<int> traverse2;
	inorderTraversal(root, traverse2);

    for (int element:traverse2){
        cout << element << " ";
    }
    cout << endl;

	return 0;
}
