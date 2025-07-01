#include <bits/stdc++.h>
using namespace std;

class DisJointSet{
private:
    vector<int> size, parent;
    
public:
    DisJointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for (int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    int findUltimateParent(int node){
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void findUnionBySize(int u, int v){
        int upar_u = findUltimateParent(u), upar_v = findUltimateParent(v);
        if (upar_u == upar_v) return;
        
        if (size[upar_u] <= size[upar_v]){
             parent[upar_u] = upar_v; 
             size[upar_v] = upar_v + upar_u;
        } else {
            parent[upar_v] = upar_u;
            size[upar_u] = upar_u + upar_v;
        } 
    }
};

class Solution {
  public:
    static bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
        return a.first <= b.first;
    }
    
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        DisJointSet* ds = new DisJointSet(V);
        vector<pair<int, pair<int, int>>> edges;
        int cost = 0;
        
        for (int u=0; u<V; u++){
            for (auto it: adj[u]){
                int v = it[0], w = it[1];
                edges.push_back({w, {u, v}});
            }
        }
        
        sort(edges.begin(), edges.end(), cmp);
        
        for (int i=0; i<edges.size(); i++){
            int w = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
            if (ds->findUltimateParent(u) == ds->findUltimateParent(v)) continue;
            cost = cost + w;
            ds->findUnionBySize(u, v);
        }
        
        return cost;
    }
};

int main(){
    int n, e;
    
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter E: ";
    cin >> e;
    
    vector<vector<int>> edges[n];
    for (int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp = {v, w};
        edges[u].push_back(temp);
    }

    Solution* s = new Solution();
    cout << s->spanningTree(n, edges) << endl;

    return 0;
}