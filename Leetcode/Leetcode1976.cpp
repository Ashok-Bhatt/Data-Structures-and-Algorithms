#include<bits/stdc++.h>
using namespace std;

class cmp{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};

int countPaths(int n, vector<vector<int>>& roads) {
    
    int totalRoads = roads.size();
    vector<vector<pair<int, int>>> adjList(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<pair<int, int>> shortest(n, {INT_MAX, 0});

    shortest[0] = {0, 1};

    for (int i=0; i<totalRoads; i++){
        int u = roads[i][0], v = roads[i][1], w = roads[i][2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    for (int i=0; i<adjList[0].size(); i++){
        pair<int, int> element = adjList[0][i];
        int next = element.first, weight = element.second;
        pq.push(element);
        shortest[next] = {weight, 1};
    }

    while (!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int current = top.first, weight = top.second;
        
        for (int i=0; i<adjList[current].size(); i++){
            pair<int, int> element = adjList[current][i];
            int next = element.first, nextWeight = weight + element.second;
            if (nextWeight < shortest[next].first){
                shortest[next] = {nextWeight, shortest[current].second};
                pq.push({next, nextWeight});
            } else if (nextWeight == shortest[next].first) {
                shortest[next].second = shortest[next].second + shortest[current].second;
                pq.push({next, nextWeight});
            }
        }
    }

    return shortest[n-1].second;
}

int main(){

    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> edges(n, vector<int>(3, 0));

    for (int i=0; i<m; i++){
        for (int j=0; j<3; j++){
            cin >> edges[i][j];
        }
    }

    int ans = countPaths(n, edges);
    cout << ans << endl;
}