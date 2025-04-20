#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void printQueue(queue<int> q){
    while (!q.empty()){
        int element = q.front();
        q.pop();
        cout << element << " ";
    }
    cout << endl;
}

int main(){

    queue<int> q1;
    q1.push(3);
    q1.push(4);
    q1.push(34);
    q1.push(6);

    int n = q1.size();
    int k = 4;

    cout << "Queue before reversing: " << endl;
    printQueue(q1);

    stack<int> s;
    for (int i=0; i<k; i++){
        int element = q1.front();
        q1.pop();
        s.push(element);
    }

    while (!s.empty()){
        int element = s.top();
        s.pop();
        q1.push(element);
    }

    for (int i=0; i<(n-k); i++){
        int element = q1.front();
        q1.pop();
        q1.push(element);
    }

    cout << "Queue after reversing: " << endl;
    printQueue(q1);
}