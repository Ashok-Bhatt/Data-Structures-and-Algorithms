#include <iostream>
#include <stack>
using namespace std;

int main(){

    string input = "(a+b)+(b)";
    stack<int> ans;

    int size = input.length();
    int redundancy = true;

    for (int i=0; i<size; i++){
        if (input[i] == '(' || input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/'){
            ans.push(input[i]);
        }
        else if (input[i] == ')'){
            redundancy = true;
            while (!ans.empty() && ans.top()!='('){
                redundancy = false;
                ans.pop();
            }
            ans.pop();

            if (redundancy){
                cout << "Redundancy found! " << endl;
                break;
            }
        }
    }

    if (!redundancy){
        cout << "Redundancy not found! " << endl;
    }

}