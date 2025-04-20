#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col){
        this->data = data;
        this->row =  row;
        this->col = col;
    }
};

class compare1{
    public:
    bool operator()(Node* a, Node* b){
        return a->data < b->data;
    }
};

int main(){

    priority_queue<Node*, vector<Node*>, compare1> maxHeap;
    maxHeap.push(new Node(1,0,1));
    maxHeap.push(new Node(4,0,2));
    maxHeap.push(new Node(11,0,1));
    maxHeap.push(new Node(46,0,2));
    cout << maxHeap.top()->data << endl;

    maxHeap.pop();
    cout << maxHeap.top()->data << endl;
}