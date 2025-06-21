#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter E: ";
    cin >> e;

    vector<vector<int>> edges(e);
    vector<int> ans(n, INT_MAX);

    for (int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >>w;
        vector<int> edge = {u, v, w};
        edges[i] = edge;
    }

    ans[0] = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<e; j++){
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (ans[u]!=INT_MAX && ans[u]+w<ans[v]){
                ans[v] = ans[u] + w;
            }
        }
    }

    cout << "Shortest Distance: " << endl;
    for (int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
}