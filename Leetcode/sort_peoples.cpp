#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printArray(vector<int> arr) {
        int n = arr.size();
        for (int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void printArray(vector<string> arr) {
        int n = arr.size();
        for (int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    vector<string> sortPeople(vector<string>& names, const vector<int>& heights) {
        int numberOfPeople = names.size();

        vector<int> sortedIndices(numberOfPeople);
        iota(begin(sortedIndices), end(sortedIndices), 0);

        sort(begin(sortedIndices), end(sortedIndices), [&heights](int a, int b) { return heights[a] > heights[b]; });

        vector<string> sortedNames;
        sortedNames.reserve(numberOfPeople);

        for (int i = 0; i < numberOfPeople; i++) {
            sortedNames.push_back(move(names[sortedIndices[i]]));
        }

        return sortedNames;
    }
};

int main(){
    Solution* s1 = new Solution();
    vector<string> names = {"Ashok", "Irfan", "Chetan", "Sonu", "Tushar", "Ankit"};
    vector<string> ans = s1->sortPeople(names, {420, 225, 930, 200, 450, 456});
}