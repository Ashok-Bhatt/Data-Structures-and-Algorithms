#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size(), i=n-1, j=n-1;
    
    while (i>=0){

        int element = nums[j];

        while (j%2==0 && nums[j]<0 && nums[i]<0){
            i--;
            swap(element, nums[i]);
        }

        while (j%2!=0 && nums[j]>0 && nums[i]>0){
            i--;
            swap(element, nums[i]);
        }

        if ((j%2==0 && nums[j]<0) || (j%2!=0 && nums[j]>0)) nums[j] = element;

        i--;
        j--;
    }

    return nums;
}

int main(){
    vector<int> nums = {2,-3,8,-5,1,-2,4,-1,6,-8};
    vector<int> ans = rearrangeArray(nums);
    for (int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}