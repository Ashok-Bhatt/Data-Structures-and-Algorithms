#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, e;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter E: ";
    cin >> e;

    vector<vector<pair<int, int>>> adjList(n);
    vector<pair<int, int>> ans(n, {-1, INT_MAX});
    priority_queue<pair<int, int>> pq;
    stack<int> pathNodes;

    for (int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    pq.push({0, 0});
    ans[0] = {-1, 0};

    while (!pq.empty()){

        pair<int, int> top = pq.top();
        int node = top.first, distance = top.second;

        pq.pop();

        for (auto it : adjList[node]){
            int nextNode = it.first, nextDistance = it.second;

            if (nextDistance + distance < ans[nextNode].second){
                ans[nextNode] = {node, nextDistance + distance};
                pq.push({nextNode, nextDistance + distance});
            }
        }
    }

    pathNodes.push(n-1);

    while (ans[pathNodes.top()].first != -1){
        pathNodes.push(ans[pathNodes.top()].first);
    }

    if (pathNodes.top() != 0){
        cout << "Path from 0 to " << n << " does not exist";
    } else {
        cout << "Path from source to destination: " << endl;
        while (!pathNodes.empty()){
            cout << pathNodes.top() << " ";
            pathNodes.pop();
        }
    }

}