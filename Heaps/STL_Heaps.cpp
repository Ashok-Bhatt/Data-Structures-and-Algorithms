#include <bits/stdc++.h>
using namespace std;

int main(){

    // Max Heap
    cout << "For Max Heap: " << endl << endl;

    priority_queue<int> heap1;
    heap1.push(12);
    heap1.push(20);
    heap1.push(100);
    heap1.push(57);
    heap1.push(51);
    cout << "Top Element: " << heap1.top() << endl;

    heap1.pop();
    heap1.pop();
    cout << "Top Element: " << heap1.top() << endl;
    cout << "Size of Heap: " << heap1.size() << endl;

    cout << "Is Heap Empty? " << heap1.empty() << endl << endl;

    // Min Heap
    cout << "For Min Heap: " << endl << endl;

    priority_queue<int, vector<int>, greater<int>> heap2;
    heap2.push(12);
    heap2.push(20);
    heap2.push(100);
    heap2.push(57);
    heap2.push(51);
    cout << "Top Element: " << heap2.top() << endl;

    heap2.pop();
    heap2.pop();
    cout << "Top Element: " << heap2.top() << endl;
    cout << "Size of Heap: " << heap2.size() << endl;

    cout << "Is Heap Empty? " << heap2.empty() << endl;
}