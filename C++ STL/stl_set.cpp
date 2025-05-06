#include <iostream>
#include <set>
using namespace std;

int main() {

    set<int> num;
    num.insert(5);
    num.insert(2);
    num.insert(1);
    num.insert(2);
    num.insert(2);
    num.insert(6);

    for (auto i:num){
        cout << i << " ";
    }
    cout << endl;

    num.erase(num.begin());
    for (auto i:num){
        cout << i << " ";
    }
    cout << endl;

    set<int>::iterator it = num.begin();
    it++;
    it++;    // Pointing towards the last element

    num.erase(it);
    for (auto i:num){
        cout << i << " ";
    }
    cout << endl;

    cout << num.count(2) << endl;
    cout << num.count(1) << endl;

    set<int>::iterator itr = num.find(2);
    set<int>::iterator itr2 = num.find(5);

    for (auto it=itr; it!=num.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    for (auto it=itr2; it!=num.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    
}