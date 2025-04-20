#include <iostream>
#include <deque>
using namespace std;

int main() {

    deque<int> d;

    cout << "Is deque Empty: " << d.empty() << endl;

    d.push_back(34);
    cout << "Front: " << d.front() << "\t" << "Rear: " << d.back() << endl;

    d.push_front(45);
    cout << "Front: " << d.front() << "\t" << "Rear: " << d.back() << endl;

    d.push_back(23);
    cout << "Front: " << d.front() << "\t" << "Rear: " << d.back() << endl;

    d.pop_front();
    cout << "Front: " << d.front() << "\t" << "Rear: " << d.back() << endl;

    d.pop_back();
    cout << "Front: " << d.front() << "\t" << "Rear: " << d.back() << endl;

    cout << "Size of deque: " << d.size() << endl;
}