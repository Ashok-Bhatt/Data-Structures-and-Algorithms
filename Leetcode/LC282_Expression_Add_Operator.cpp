#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isFeasibleSolution(string &temp, int target){
        string num = "";
        vector<string> inOrder, postOrder;
        stack<string> st;
        stack<long long> evaluate;
        unordered_map<string, int> priority = {{"*", 2}, {"-", 1}, {"+", 1}};
        long long sum = 0;
        
        // Braaking the string into vector of strings as a collection of operators and operands E.g. 7+86-9 ==> [7,+,86,-,9]
        for (int i=0; i<temp.size(); i++){
            if (temp[i]<'0' || temp[i]>'9'){
                string x(1, temp[i]);
                inOrder.push_back(num);
                inOrder.push_back(x);
                num = "";
            } else {
                num.push_back(temp[i]);
                if (i == temp.size()-1){
                    inOrder.push_back(num);
                }
            }
        }

        // Converting inOrder array to postOrder as postorder is easy to evaluate in O(n) time
        for (int i=0; i<inOrder.size(); i++){
            string element = inOrder[i];
            if (element=="+" || element=="-" || element=="*"){
                while (!st.empty() && priority[st.top()]>=priority[element]){
                    postOrder.push_back(st.top());
                    st.pop();
                }
                st.push(element);
            } else {
                postOrder.push_back(element);
            }
        }

        while (!st.empty()){
            postOrder.push_back(st.top());
            st.pop();
        }

        // Evaluating Postorder array to get the result
        for (int i=0; i<postOrder.size(); i++){
            string element = postOrder[i];
            if (element=="+" || element=="-" || element=="*"){
                long long first = evaluate.top();
                evaluate.pop();
                long long second = evaluate.top();
                evaluate.pop();

                long long newNum;
                if (element == "+") newNum = second + first;
                if (element == "-") newNum = second - first;
                if (element == "*") newNum = second * first;
                evaluate.push(newNum);
            } else {
                evaluate.push(stoll(element));
            }
        }

        return (long long)target == evaluate.top();
    }

    void solve(string &num, int target, int index, int n, string &temp, vector<string> &ans){

        if (index==n){
            if (isFeasibleSolution(temp, target)) ans.push_back(temp);
            return;
        }


        if (index==0){
            temp.push_back(num[index]);
            solve(num, target, index+1, n, temp, ans);
            temp.pop_back();
        } else {
            vector<char> operators = {'+', '-', '*', ' '};
            for (auto op : operators){
                if (op != ' ') temp.push_back(op);
                temp.push_back(num[index]);
                solve(num, target, index+1, n, temp, ans);
                if (op != ' ') temp.pop_back();
                temp.pop_back();
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        string temp = "";
        int n = num.size(), index = 0;
        vector<string> ans;
        solve(num, target, index, n, temp, ans);
        return ans;
    }
};

int main(){
    Solution* s1 = new Solution();
    vector<string> ans = s1->addOperators("22", 4);
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}