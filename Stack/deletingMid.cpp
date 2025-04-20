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

void deleteMid (stack<int> &s, int size, int index){

    if (index==size/2){
        s.pop();
        return;
    }
    
    int peek = s.top();
    s.pop();
    deleteMid (s, size, index+1);
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

    int size1 = s1.size();
    deleteMid(s1, size1, 0);

    cout << "Stack(top-->bottom) after deleting mid: " << endl;
    printStack(s1);

}