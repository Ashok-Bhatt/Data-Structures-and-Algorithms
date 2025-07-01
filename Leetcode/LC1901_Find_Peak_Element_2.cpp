#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLargest(vector<int> &mat, int n)
    {
        int largest = 0;
        for (int i = 1; i < n; i++)
        {
            if (mat[i] > mat[largest])
            {
                largest = i;
            }
        }
        return largest;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans = {-1, -1};
        int s = 0, e = n - 1, mid;

        while (s <= e)
        {
            mid = s + (e - s) / 2;
            int largest = findLargest(mat[mid], m);
            if ((mid == s || mat[mid][largest] > mat[mid - 1][largest]) && (mid == e || mat[mid][largest] > mat[mid + 1][largest]))
            {
                ans = {mid, largest};
                break;
            }
            else if (mid == s || (mid != e && mat[mid + 1][largest] > mat[mid - 1][largest]))
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution *s1 = new Solution();
    vector<vector<int>> mat = {{48, 36, 35, 17, 48}, {38, 28, 38, 26, 24}, {15, 9, 33, 32, 6}, {49, 4, 8, 10, 41}};
    vector<int> ans = s1->findPeakGrid(mat);
    cout << ans[0] << " " << ans[1] << endl;
}