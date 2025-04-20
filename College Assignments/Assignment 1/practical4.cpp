
/* 
Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp. For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]). 

Note: The drive code prints "balanced" if function return true, otherwise it prints "not 
balanced". 

Example 1: 
Input: 
{([])} 
Output: 
true 

Explanation: { ( [ ] ) }. Same colored brackets can form balanced pairs, with 0 number of unbalanced bracket
 */

#include <bits/stdc++.h>
using namespace std;

bool isValidString(string expr){

    stack<char> storage;
    int n = expr.size();

    for (int i=0; i<n; i++){
        if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']'){
            if (storage.empty()){
                return false;
            } else if ((storage.top() == '(' && expr[i] == ')') || (storage.top() == '{' && expr[i] == '}') || (storage.top() == '[' && expr[i] == ']')){
                storage.pop();
            } else {
                storage.push(expr[i]);
            }
        } else {
            storage.push(expr[i]);
        }
    }

    return storage.empty();
}

int main(){

    string expr = "{({}){([{{}}])}}";
    bool flag = isValidString(expr);

    cout << "String: " << expr << endl;
    if (flag){
        cout << "Valid String." << endl;
    } else {
        cout << "Invalid String." << endl;
    }
}