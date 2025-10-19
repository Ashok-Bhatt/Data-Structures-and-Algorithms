#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int testNo = 1; testNo <= t; testNo++)
    {
        int n, ans = 0;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, abs(arr[i + 1] - arr[i]));
        }

        cout << "Case #" << testNo << ": " << ans << endl;
    }
}