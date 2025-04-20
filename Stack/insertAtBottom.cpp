#include<iostream>
#include<stack>
using namespace std;

void printStack (stack<int> s){

    while (!s.empty()){
        int peek = s.top();
        s.pop();
        cout << peek << "  ";
    }
    cout << endl;

}

void insertAtBottom (stack<int> &s, int element){

    if (s.empty()){
        s.push(element);
        return;
    }
    
    int peek = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(peek);

}

int main(){

    stack<int> s1;
    s1.push(23);
    s1.push(12);
    s1.push(2);
    s1.push(100);
    s1.push(3);
    s1.push(43);

    cout << "Stack(top-->bottom) before deleting mid:" << endl;
    printStack(s1);

    int element = 6;
    insertAtBottom(s1,element);

    cout << "Stack(top-->bottom) after deleting mid: " << endl;
    printStack(s1);

}