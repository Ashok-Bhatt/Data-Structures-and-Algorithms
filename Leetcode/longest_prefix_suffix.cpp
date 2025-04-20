#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestPrefixSuffix(string &s) {
        
    int n = s.size(), i = 0, j = 1;
    vector<int> longestPrefixSuffix(n, 0);
    
    while (j<n){
        while (i>=0 && s[j] != s[i]){
            i--;
            cout << i << " ";
            if (i >= 0){
                i = longestPrefixSuffix[i];
            }
        }
        cout << endl;
        
        cout << i << "--------" << j << endl;
        longestPrefixSuffix[j] = i+1;
        i++;
        j++;
    }
    
    return longestPrefixSuffix[n-1];
    
}

int main(){
    string s = "aabcdaabc";
    cout << longestPrefixSuffix(s) << endl;
}