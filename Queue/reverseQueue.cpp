#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void printQueue(queue<int> x){

    while (!x.empty()){
        int element = x.front();
        x.pop();
        cout << element << " ";
    }
    cout << endl;

}

void reverse1(queue<int> x){
    
    stack<int> intermediate;

    while (!x.empty()){
        int element = x.front();
        x.pop();
        intermediate.push(element);
    }

    while (!intermediate.empty()){
        int element = intermediate.top();
        intermediate.pop();
        x.push(element);
    }

    printQueue(x);

}

void reverseQueue(queue<int> &x){

    if (x.empty()){
        return;
    }

    int element = x.front();
    x.pop();
    reverseQueue(x);
    x.push(element);
}

void reverse2 (queue<int> x){
    reverseQueue(x);
    printQueue(x);
}

int main(){

    queue<int> q;
    q.push(3);
    q.push(33);
    q.push(333);
    q.push(3333);

    cout << "Before reversing: " << endl;
    printQueue(q);

    cout << "After reversing using stack: " << endl;
    reverse1(q);

    cout << "After reversing using recursion: " << endl;
    reverse2(q);
}