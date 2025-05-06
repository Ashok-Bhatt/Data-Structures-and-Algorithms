#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<string> s;

    s.push("Ashok");
    s.push("Bhatt");
    s.push("AB");

    cout << "Top Element: " << s.top() << endl;

    s.pop();
    cout << "Top Element: " << s.top() << endl;

    cout << "Size: " << s.size() << endl;
    cout << "Is Stack Empty? " << s.empty() << endl;
    
}