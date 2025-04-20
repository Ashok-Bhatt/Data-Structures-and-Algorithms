
#include <bits/stdc++.h>
using namespace std;

double minimumAverage(vector<int>& nums) {
        
    double mini = double(INT_MAX);
    int n = nums.size(), i = 0, j = n-1;
    vector<double> averages;
    
    sort(nums.begin(), nums.end());
    
    while (i < j){
        double result = 1.0*(nums[i++] + nums[j--])/2;
        averages.push_back(result);
        mini = min(mini, result);
    }
    
    return mini;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8};
    cout << minimumAverage(nums) << endl;
}