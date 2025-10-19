#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> &arr, int n){
    int ans = 0;
    for (int i=0; i<n; i++){
        ans = max(ans, arr[i]);
    }
    return ans;
}

bool isFeasibleSolution(vector<int> &arr, int n, int mid){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n, false);

    for (int i=0; i<n; i++){
        pq.push({arr[i], i});
    }

    while (!pq.empty()){
        pair<int, int> top = pq.top();
        int value = top.first, index = top.second;
        pq.pop();

        if (!visited[index]){
            if (value > mid){
                return false;
            } else {
                int leftIndex = index-1, rightIndex = index+1;
                visited[index] = true;
                
                while (leftIndex>=0 && !visited[leftIndex]){
                    if (abs(arr[leftIndex] - arr[leftIndex+1]) > mid){
                        break;
                    } else {
                        visited[leftIndex] = true;
                        leftIndex--;
                    }
                }

                while (rightIndex<n && !visited[rightIndex]){
                    if (abs(arr[rightIndex] - arr[rightIndex-1]) > mid){
                        break;
                    } else {
                        visited[rightIndex] = true;
                        rightIndex++;
                    }
                }
            }
        }
    }

    return true;
}

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
        int n, ans = INT_MAX;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int s = 0, e = getMax(arr, n), mid;
        while (s<=e){
            mid = s + (e-s)/2;
            if (isFeasibleSolution(arr, n, mid)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        cout << "Case #" << testNo << ": " << ans << endl;
    }
}