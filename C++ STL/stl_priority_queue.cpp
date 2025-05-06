#include <iostream>
#include <queue>
using namespace std;

int main() {

    // Priority Queue is the type of queue in which the largest element is popped

    // Max Heap
    priority_queue<int> maxi;

    // Min Heap;
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(45);
    maxi.push(54);
    maxi.push(23);
    maxi.push(50);
    
    int n = maxi.size();
    for (int i=0; i<n; i++){
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;

    mini.push(45);
    mini.push(54);
    mini.push(23);
    mini.push(50);

    int n1 = mini.size();
    for (int i=0; i<n1; i++){
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;
}