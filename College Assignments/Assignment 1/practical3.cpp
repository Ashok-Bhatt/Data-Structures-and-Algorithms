
/* 
Question : Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

Note: If at any instance, there are no more subarrays of size greater than or equal to K, then reverse the last subarray (irrespective of its size). You shouldn't return any array, modify the given array in-place. 

Example 1: 
Input: 
N = 5, K = 3 
arr[] = {1,2,3,4,5} 
Output: 3 2 1 5 4 

Explanation: First group consists of elements 
1, 2, 3. Second group consists of 4,5. 

 */

#include <bits/stdc++.h>
using namespace std;

void reverseSubarrays(vector<int> &nums, int n, int k){

    int i = 0, j = min(k-1, n-1);
    while (i < n){
        int s = i, e = j;
        while (s < e){
            swap(nums[s++], nums[e--]);
        }

        i = i + k;
        j = min (j+k, n-1);

    }
}

int main(){

    int n = 14, k = 3;
    vector<int> nums = {1, 4, 5, 3, 6, 2, 7, 8, 12, 45, 56, 23, 56, 2};

    cout << "Input: ";
    for (int i=0; i<n; i++){
        cout << nums[i] << " ";
    }

    reverseSubarrays(nums, n, k);

    cout << endl << "Output: ";
    for (int i=0; i<n; i++){
        cout << nums[i] << " ";
    }
}