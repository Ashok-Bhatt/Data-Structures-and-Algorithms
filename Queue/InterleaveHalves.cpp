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

void interleaveUsingQueue(queue<int> &q1){

    queue<int> q2;
    while (q1.size() != q2.size()){
        int element = q1.front();
        q1.pop();
        q2.push(element);
    }

    while (!q2.empty()){
        
        int element1 = q2.front();
        int element2 = q1.front();

        q1.pop();
        q2.pop();

        q1.push(element1);
        q1.push(element2);
    }

}

void interleaveUsingStack(queue<int> &q1){

    stack<int> s1;
    while (s1.size() != q1.size()){
        int element = q1.front();
        q1.pop();
        s1.push(element);
    }

    int count = s1.size();

    while (!s1.empty()){
        int element = s1.top();
        s1.pop();
        q1.push(element);
    }

    for (int i=0; i<count*2; i++){
        if (i<count){
            int element = q1.front();
            q1.pop();
            q1.push(element);
        }
        else{
            int element = q1.front();
            q1.pop();
            s1.push(element);
        }
    }

    while (!s1.empty()){

        int element1 = s1.top();
        int element2 = q1.front();

        s1.pop();
        q1.pop();

        q1.push(element1);
        q1.push(element2);
    }

}

int main() {

    // Interleaving using queue

    cout << "Interleaving using queue: " << endl << endl;

    queue<int> full1;
    for (int i=1; i<=10; i++){
        full1.push(i);
    }

    cout << "Queue before interleaving: " << endl;
    printQueue(full1);

    interleaveUsingQueue(full1);

    cout << "Queue after interleaving: " << endl;
    printQueue(full1);

    cout << endl;
    
    // Interleaving using stack

    cout << "Interleaving using stack: " << endl << endl;

    queue<int> full2;
    for (int i=1; i<=10; i++){
        full2.push(i);
    }

    cout << "Queue before interleaving: " << endl;
    printQueue(full2);

    interleaveUsingStack(full2);

    cout << "Queue after interleaving: " << endl;
    printQueue(full2);
}