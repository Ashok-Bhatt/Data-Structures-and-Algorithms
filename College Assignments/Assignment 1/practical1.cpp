
/* 
Question : Given an array arr[] of n positive integers. Your task is to find the leaders in the array. An element of the array is a leader if it is greater than all the elements to its right side or if it is equal to the maximum element on its right side. The rightmost element is always a leader. 

Examples :
Input: n = 6, arr[] = {16,17,4,3,5,2} 
Output: 17 5 2 

Explanation: Note that there is nothing great on the right sides of 17, 5 and 2.  
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getLeader(int n, vector<int> &nums){

    vector<int> ans;
    int maxi = INT_MIN;

    for (int i=n-1; i>=0; i--){
        if (nums[i] >= maxi){
            maxi = nums[i];
            ans.push_back(nums[i]);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    int n = 7;
    vector<int> nums = {100, 40, 56, 34, 21, 3, 2};
    vector<int> leader = getLeader(n, nums);

    cout << "Input: ";
    for (int i=0; i<n; i++){
        cout << nums[i] << " ";
    }

    cout << endl << "Output: ";
    for (int i=0; i<leader.size(); i++){
        cout << leader[i] << " ";
    }
}