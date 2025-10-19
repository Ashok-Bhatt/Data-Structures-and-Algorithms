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
        int n, a, b;
        cin >> n >> a >> b;

        cout << "Case #" << testNo << ": ";
        for (int i=0; i<2*n; i++){
            if (i==2*n-1){
                cout << b << " ";
            } else {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }
}