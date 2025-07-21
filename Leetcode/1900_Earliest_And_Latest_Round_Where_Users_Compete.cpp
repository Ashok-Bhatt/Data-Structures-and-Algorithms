#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getEarliest(int n, int firstPlayer, int secondPlayer, vector<bool> earliestUsed, int i, int j, int level){

        while (i<n && earliestUsed[i]==true) i++;
        while (j>=0 && earliestUsed[j]==true) j--;

        if (i>=j){
            return 1 + getEarliest(n, firstPlayer, secondPlayer, earliestUsed, 0, n-1, level+1);
        } else if (i==firstPlayer && j==secondPlayer){
            return 1;
        } else if (i==firstPlayer || i==secondPlayer){
            earliestUsed[j] = true;
            return getEarliest(n, firstPlayer, secondPlayer, earliestUsed, i+1, j-1, level);
        } else if (j==firstPlayer || j==secondPlayer){
            earliestUsed[i] = true;
            return getEarliest(n, firstPlayer, secondPlayer, earliestUsed, i+1, j-1, level);
        } else {
            int mini = INT_MAX;
            earliestUsed[i] = true;
            mini = min(mini, getEarliest(n, firstPlayer, secondPlayer, earliestUsed, i+1, j-1, level));
            earliestUsed[i] = false;
            earliestUsed[j] = true;
            mini = min(mini, getEarliest(n, firstPlayer, secondPlayer, earliestUsed, i+1, j-1, level));
            earliestUsed[j] = false;
            return mini;
        }
    }

    int getLatest(int n, int firstPlayer, int secondPlayer, vector<bool> latestUsed, int i, int j, int level){

        while (i<n && latestUsed[i]==true) i++;
        while (j>=0 && latestUsed[j]==true) j--;

        if (i>=j){
            return 1 + getLatest(n, firstPlayer, secondPlayer, latestUsed, 0, n-1, level+1);
        } else if (i==firstPlayer && j==secondPlayer){
            return 1;
        } else if (i==firstPlayer || i==secondPlayer){
            latestUsed[j] = true;
            return getLatest(n, firstPlayer, secondPlayer, latestUsed, i+1, j-1, level);
        } else if (j==firstPlayer || j==secondPlayer){
            latestUsed[i] = true;
            return getLatest(n, firstPlayer, secondPlayer, latestUsed, i+1, j-1, level);
        } else {
            int maxi = INT_MIN;
            latestUsed[i] = true;
            maxi = max(maxi, getLatest(n, firstPlayer, secondPlayer, latestUsed, i+1, j-1, level));
            latestUsed[i] = false;
            latestUsed[j] = true;
            maxi = max(maxi, getLatest(n, firstPlayer, secondPlayer, latestUsed, i+1, j-1, level));
            latestUsed[j] = false;
            return maxi;
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> ans = {0, 0};
        vector<bool> earliestUsed(n, false), latestUsed(n, false);

        ans[1] = getLatest(n, firstPlayer-1, secondPlayer-1, latestUsed, 0, n-1, 1);
        ans[0] = getEarliest(n, firstPlayer-1, secondPlayer-1, earliestUsed, 0, n-1, 1);
        return ans;
    }
};

int main(){
    Solution* s1;
    vector<int> ans = s1->earliestAndLatest(5,1,5);
    cout << ans[0] << " " << ans[1] << endl;
}