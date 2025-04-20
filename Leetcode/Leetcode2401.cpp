#include<bits/stdc++.h>
using namespace std;

int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size(), ans = 1, current = 0, i = 0, j = 0;
    while (j < n){
        cout << i << " " << j << endl;
        if ((current & nums[j]) == 0){
            current = current ^ nums[j];
            ans = max(ans, j-i+1);
            j++;
        } 

        while ((current & nums[j]) != 0){
            current = current ^ nums[i];
            i++;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {536870399, 890391654};
    cout << longestNiceSubarray(nums) << endl;
}