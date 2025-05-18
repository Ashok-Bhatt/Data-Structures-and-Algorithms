#include<bits/stdc++.h>
using namespace std;

int main(){

    string input;
    cout << "Enter expression: ";
    cin >> input;

    int n = input.size();
    stack<string> st;

    for (int i=n-1; i>=0; i--){
        if (isalnum(input[i])){
            string x(1, input[i]);
            st.push(x);
        } else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            st.push("(" + top1 + input[i] + top2 + ")");
        }
    }

    cout << st.top() << endl;

}