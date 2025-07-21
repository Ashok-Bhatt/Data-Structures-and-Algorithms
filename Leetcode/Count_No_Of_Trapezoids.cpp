#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        long long ans = 0;
        unordered_map<int, int> mapping;
        unordered_map<int, long long> factorial;
        vector<long long> sides;
        vector<long long> prefix;

        for (int i=0; i<n; i++){
            int x = points[i][0], y = points[i][1];
            mapping[y]++;
        }

        for (int i=0; i<n; i++){
            if (i==0){
                factorial[i] = 0;
            } else {
                factorial[i] = (factorial[i-1] + i)%(long long)(1e9+7);
            }
        }

        for (auto it : mapping){
            if (factorial[it.second-1] >= 1){
                sides.push_back(factorial[it.second-1]);
            }
        }

        prefix.resize(sides.size(), 0);
        for (int i=0; i<sides.size(); i++){
            if (i==0){
                prefix[i] = sides[i];
            } else {
                prefix[i] = (prefix[i-1] + sides[i]) % (long long)(1e9+7);
            }
        }

        for (int i=0; i<sides.size(); i++){
            cout << sides[i] << "->" << prefix[i] << "    ";
        }

        for (int i=0; i<sides.size(); i++){
            long long sum = (prefix[sides.size()-1]-prefix[i] + (long long)(1e9+7));
            ans = (ans + (sides[i] * sum) % (long long)(1e9+7) ) % (long long)(1e9+7);
        }

        return (int)ans;
    }
};

int main(){

    Solution* s1 = new Solution();
    vector<vector<int>> points = {{1,0}, {2,0}, {3,0}, {2,2}, {3,2}};
    cout << s1->countTrapezoids(points) << endl;
}