#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, e;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter e: ";
    cin >> e;

    vector<vector<int>> adjList(n);
    vector<int> ans;
    vector<int> inDegree(n, 0);
    queue<int> q;
    vector<bool> visited(n, false);

    for (int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    for (int i=0; i<n; i++){
        for (auto neighbour : adjList[i]){
            inDegree[neighbour]++;
        }
    }

    // for (int i=0; i<n; i++){
    //     cout << inDegree[i] << " ";
    // }
    // cout << endl;

    for (int i=0; i<n; i++){
        if (inDegree[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()){
        int front = q.front();
        ans.push_back(front);
        q.pop();

        for (auto neighbor : adjList[front]){
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }

    cout << endl << "Topological sort ordering: ";
    for (auto element : ans){
        cout << element << " ";
    }
}