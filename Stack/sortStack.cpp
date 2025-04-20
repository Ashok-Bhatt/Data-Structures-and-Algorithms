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

void pushBottom(stack<int> &s, int element){

    if (s.empty() || s.top()<=element){
        s.push(element);
    }
    else{
        int peek = s.top();
        s.pop();
        pushBottom(s, element);
        s.push(peek);
    }

}

void sortStack (stack<int> &s){

    if (s.empty())
        return;
    
    int peek = s.top();
    s.pop();
    sortStack(s);
    pushBottom(s,peek);

}

int main(){

    stack<int> s1;
    s1.push(23);
    s1.push(12);
    s1.push(12);
    s1.push(100);
    s1.push(3);
    s1.push(43);

    cout << "Stack before sorting: " << endl;
    printStack(s1);

    sortStack(s1);

    cout << "Stack after sorting: " << endl;
    printStack(s1);

}