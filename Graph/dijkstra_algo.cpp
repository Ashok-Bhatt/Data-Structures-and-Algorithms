#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, e;
    
    cout << "Enter N: ";
    cin >> n;

    cout << "Enter E: ";
    cin >> e;

    vector<vector<pair<int, int>>> adjList(n);
    vector<int> ans(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    ans[0] = 0;
    pq.push({0, 0});

    for (int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    while (!pq.empty()){
        
        pair<int, int> top = pq.top();
        int distance = top.first, node = top.second;
        pq.pop();

        for (auto it : adjList[node]){
            int nextNode = it.first, nextDistance = it.second;
            if (distance + nextDistance < ans[nextNode]){
                pq.push({distance+nextDistance, nextNode});
                ans[nextNode] = min(ans[nextNode] , distance + nextDistance);
            }
        }
    }

    for (int i=0; i<n; i++){
        if (ans[i] == INT_MAX){
            cout << "-1 ";
        } else {
            cout << ans[i] << " ";
        }
    }

}