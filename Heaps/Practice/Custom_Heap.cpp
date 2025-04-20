#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
    int x, y;

    Node(int x, int y){
        this->x = x;
        this->y = y;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return (a->x < b->x) || (a->x == b->x && a->y < b->y);
    }
};

int main(){

    priority_queue<Node*, vector<Node*>, compare> maxHeap;
    vector<Node*> arr = {new Node(3,5), new Node(2,7), new Node(6,4), new Node(2,8), new Node(4,1)};

    for (int i=0; i<5; i++){
        maxHeap.push(arr[i]);
    }

    while (!maxHeap.empty()){
        cout << maxHeap.top()->x << "   " << maxHeap.top()->y << endl;
        maxHeap.pop();
    }

    return 0;
}