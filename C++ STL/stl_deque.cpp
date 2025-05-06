#include <iostream>
#include <deque>
using namespace std;

void printQueue(deque<int> x, int para){
    
    if (para==1)
        cout << endl << "Queue elements: " << endl;
    
    for (int i:x)
        cout << i << " ";
    cout << endl;
}

int main() {

    deque<int> queue;
    printQueue(queue, 1);

    queue.push_back(4);
    printQueue(queue, 1);

    queue.push_front(3);
    printQueue(queue, 1);

    queue.push_back(100);
    printQueue(queue, 1);

    queue.pop_front();
    printQueue(queue, 1);

    cout << endl << "Is Queue Empty: ";
    cout << bool(queue.empty()) << endl;

    queue.erase(queue.begin() , queue.begin()+1);
    printQueue(queue, 1);

}