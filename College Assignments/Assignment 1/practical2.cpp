/* 
Question: Given an array Arr consisting of N distinct integers. The task is to count all the triplets such that sum of two elements equals the third element. 

Example 1:
Input: 
N = 4 
arr[] = {1, 5, 3, 2} 
Output: 2 

Explanation: There are 2 triplets: 
 1 + 2 = 3 and 3 + 2 = 5 

 */

#include <bits/stdc++.h>
using namespace std;

int getTriplets(int n, vector<int> nums){

    int ans = 0, target;
    sort(nums.begin(), nums.end());

    for (int k=n-1; k>=0; k--){
        int i = 0, j = k-1;
        target = nums[k];
        while (i < j){
            if (target == nums[i] + nums[j]){
                ans++;
                if (nums[i+1] == nums[i] || nums[j-1] != nums[j]){
                    i++;
                } else {
                    j--;
                }
            } else if (target < nums[i] + nums[j]){
                j--;
            } else {
                i++;
            }
        }
    }

    return ans;
}

int main(){

    int n = 4, ans = 0;
    vector<int> nums = {1,5,3,2};
    ans = getTriplets(n, nums);

    cout << "Input: ";
    for (int i=0; i<n; i++){
        cout << nums[i] << " ";
    }

    cout << endl << "Output: " << ans << endl;
}