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

void sortedInsert(stack<int> &s, int peek){

    if (s.empty()){
        return;
    }

    else{
        if (s.empty() || s.top()<peek){
            s.push(peek);
        }
        else{
            int element = s.top();
            s.pop();
        }
    }

}

void sortStack(stack<int> &s){

    if (s.empty())
        return;
    
    int peek = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s,peek);

}

int main(){

    stack<int> s1;
    s1.push(23);
    s1.push(12);
    s1.push(2);
    s1.push(100);
    s1.push(3);
    s1.push(43);

    cout << "Stack before sorting: " << endl;
    printStack(s1);

    sortStack(s1);

    cout << "Stack after sorting: " << endl;
    printStack(s1);

}