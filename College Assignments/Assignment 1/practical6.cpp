
/* 
Question: Given an input stream A of n characters consisting only of lower-case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

NOTE: 
1. You need to find the answer for every i (0 <= i < n) 
2. In order to find the solution for every i you need to consider the string from starting position till ith position. 

Example 1: 
Input: A = "aabc" 
Output: "a#bb"
 */

#include <bits/stdc++.h>
using namespace std;

string solve(string input){

    string ans;
    queue<char> q;
    unordered_map<char, bool> mapping;
    int i = 0;

    while (input[i] != '\0'){

        char c = input[i];
        if (mapping.find(c) == mapping.end()){
            mapping[c] = true;
            q.push(c);
        } else {
            mapping[c] = false;
        }

        while (!q.empty() && mapping[q.front()] == false){
            q.pop();
        }

        if (q.size() == 0){
            ans.push_back('#');
        } else {
            ans.push_back(q.front());
        }

        i++;
    }

    return ans;
}

int main() {

    string input = "aabc";
    string output = solve(input);

    cout << "Input String: " << input << endl;
    cout << "Output String: " << output << endl;
}