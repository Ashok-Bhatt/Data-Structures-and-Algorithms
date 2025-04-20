#include<iostream>
#include<stack>
using namespace std;

bool checkParenthesis(string parenthesis){

    stack<char> s1;
    int length = parenthesis.length();

    for (int i=0; i<length; i++){

        char character = parenthesis[i];

        if ((character=='(') || (character=='{') || (character=='[')){
            s1.push(character);
        }
        else{
            if (s1.empty()){
                return 0;
            }
            else{
                if ((s1.top()=='(' && character==')') || (s1.top()=='{' && character=='}') || (s1.top()=='[' && character==']')){
                    s1.pop();
                }
                else{
                    return 0;
                }
            }
        }
        
    }

    return 1;

}

int main(){

    string parenthesis = "{[[()]]}";
    bool ans = checkParenthesis(parenthesis);

    if (ans)
        cout << "Valid Parenthesis!" << endl;
    else
        cout << "Invalid Parenthesis!" << endl;

}