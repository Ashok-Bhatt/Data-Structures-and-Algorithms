#include<bits/stdc++.h>
using namespace std;

bool isAlphanumeric(char x){
    return (x>='A' && x<='Z') || (x>='a' && x<='z') || (x>='0' && x<='9');
}

int main(){

    string input;
    cout << "Enter expression: ";
    cin >> input;

    int n = input.size();
    string ans = "";
    stack<char> st;

    unordered_map<char, int> priority;
    priority['^'] = 3;
    priority['*'] = priority['/'] = 2;
    priority['+'] = priority['-'] = 1;
    priority[')'] = 0;

    reverse(input.begin(), input.end());

    for (int i=0; i<n; i++){
        if (isAlphanumeric(input[i])){
            ans.push_back(input[i]);
        } else if (input[i] == ')'){
            st.push(input[i]);
        } else if (input[i] == '('){
            while (!st.top() == ')'){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && priority[st.top()] > priority[input[i]]){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(input[i]);
        }
    }

    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}