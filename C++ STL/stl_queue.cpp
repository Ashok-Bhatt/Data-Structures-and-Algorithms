#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<string> q;

    q.push("Ashok");
    q.push("Ashok1");
    q.push("Ashok2");
    cout << "Top Element: " << q.front() << endl;

    q.pop();
    cout << "Top Element: " << q.front() << endl;

    cout << "Is Queue empty? " << q.empty() << endl;
}