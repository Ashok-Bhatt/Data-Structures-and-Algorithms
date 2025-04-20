#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long countBadPairs(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> numsToIndex;
    long long goodPairs = 0;

    for (int i=0; i<n; i++){
        numsToIndex.push_back({nums[i], i});
    }

    sort(numsToIndex.begin(), numsToIndex.end());

    int i = 0, j = 0, spaces = 0;
    while (j <= n){

        cout << i << " " << j << endl;

        if (j-i == 0){
            j++;
        } else if (j < n){
            if (numsToIndex[j].second-numsToIndex[i].second==numsToIndex[j].first-numsToIndex[i].first){
                j++;
            } else if (j+1<n && numsToIndex[j].first==numsToIndex[j+1].first){
                j++;
                spaces++;
            } else {
                goodPairs = goodPairs + (long long)(j-i-spaces-1)*(j-i-spaces)/2;
                i = j;
                spaces = 0;
            }
        } else {
            break;
        }
    }

    return (long long)n*(n-1)/2 - goodPairs;

}

int main(){
    vector<int> arr = {4,1,3,3};
    cout << countBadPairs(arr) << endl;
}