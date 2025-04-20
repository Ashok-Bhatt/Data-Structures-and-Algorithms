#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<int> s1;
    s1.push(4);
    s1.push(2);
    s1.push(6);
    cout << "Top Element: " << s1.top() << endl;
    s1.pop();
    cout << "Is stack empty: " << s1.empty() << endl;
    s1.pop();
    cout << "Top Element: " << s1.top() << endl;
    s1.pop();
    cout << "Is stack empty: " << s1.empty() << endl;

}