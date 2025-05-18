#include<bits/stdc++.h>
using namespace std;

int main(){

    string input;
    cout << "Enter expression: ";
    cin >> input;

    int n = input.size();
    stack<string> st;

    for (int i=0; i<n; i++){
        if (isalnum(input[i])){
            string x(1, input[i]);
            st.push(x);
        } else {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            st.push(input[i] + top2 + top1);            
        }
    }

    cout << st.top() << endl;

}