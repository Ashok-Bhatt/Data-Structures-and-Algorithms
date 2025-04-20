
#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& nums, unordered_map<int, unordered_map<int, long long>> &dp, int s, int e){
        
    if (s>e){
        return INT_MIN;
    } else if (s==e){
        return (e%2==0) ? -nums[s]: nums[s];
    } else if (dp.find(s) != dp.end() && dp[s].find(e) != dp[s].end()){
        return dp[s][e];
    }
    
    long long maxi = 0;
    for (int i=s; i<=e; i++){
        maxi = maxi + nums[i];
    }
    
    maxi = (e%2==0) ? -maxi : maxi;
    for (int i=s; s<e; i++){
        maxi = max(maxi, solve(nums, dp, s, i) + solve(nums, dp, i+1, e));
    }
    
    return dp[s][e] = maxi;
}

long long maximumTotalCost(vector<int>& nums) {
    
    int n = nums.size();
    unordered_map<int, unordered_map<int, long long>> dp;

    return solve(nums, dp, 0, n-1);
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8};
    cout << maximumTotalCost(nums) << endl;
}