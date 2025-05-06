#include <iostream>
#include <list>
using namespace std;

int main() {

    list<int> l;

    l.push_back(56);
    l.push_front(2);
    l.push_front(1);

    for (int i:l)
        cout << i << " ";
    cout << endl;

    l.erase(l.begin());
    for (int i:l)
        cout << i << " ";
    cout << endl;

    list<int> list1(10,100);
    for (int element:list1)
        cout << element << " ";
    cout << endl;
   
}