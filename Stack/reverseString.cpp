#include <iostream>
#include <stack>
using namespace std;

int main(){

    string input = "A";
    string output;

    stack<int> s1;
    for (int i=0; i<input.length(); i++){
        s1.push(input[i]);
    }

    while(!s1.empty()){
        int peek = s1.top();
        output.push_back(peek);
        s1.pop();
    }

    cout << "String before reversing: " << endl;
    cout << input << endl;

    cout << "String after reversing: " << endl;
    cout << output << endl;

}