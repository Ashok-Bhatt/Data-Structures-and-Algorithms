#include <bits/stdc++.h>
using namespace std;

class cmp{
    public:
    bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
        return a.first > b.first;
    }
};

int main(){

    int n, e;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter E: ";
    cin >> e;

    vector<vector<int>> edges;
    vector<bool> visited(n, false);
    vector<vector<pair<int, int>>> adjList(n);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
    vector<vector<int>> mcst;
    int cost = 0;

    for (int i=0; i<e; i++){
        int w, u, v;
        cin >> w;
        cin >> u;
        cin >> v;
        vector<int> temp = {w, u, v};
        edges.push_back(temp);
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    pq.push({0, {0, -1}});

    while (!pq.empty()){

        pair<int, pair<int, int>> top = pq.top();
        int distance = top.first, node = top.second.first, parent = top.second.second;
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        cost = cost + distance;

        if (parent != -1){
            vector<int> temp = {node, parent, distance};
            mcst.push_back(temp);
        }

        for (auto it : adjList[node]){
            int nextNode = it.first, weight = it.second;
            if (!visited[nextNode]){
                pq.push({weight, {nextNode, node}});
            }
        }
    }

    cout << "MCST [format: (u, v, w)]: " << endl;
    for (auto it : mcst){
        int u = it[0], v = it[1], w = it[2];
        cout << "(" << u << ", " << v << ", " << w << ")      ";
    }

    cout << endl << "Cost: " << cost;
}