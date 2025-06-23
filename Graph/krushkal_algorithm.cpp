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
        if (node == parent[node]){
            return node;
        } else {
            return parent[node] = findUltimateParent(parent[node]);
        }
    }

    void unionBySize(int u, int v){
        int upar_u = findUltimateParent(u), upar_v = findUltimateParent(v);
        if (size[upar_u] >= size[upar_v]){
            parent[upar_v] = upar_u;
            upar_u = upar_u + upar_v;
        } else {
            parent[upar_u] = upar_v;
            upar_v = upar_v + upar_u;
        }
    }
};

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] <= b[2];
}

int main(){

    int n, e;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter E: ";
    cin >> e;

    DisJointSet* ds = new DisJointSet(n);
    vector<vector<int>> edges(e);
    vector<vector<int>> mcst;
    int cost = 0;

    for (int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp = {u, v, w};
        edges[i] = temp;
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i=0; i<e; i++){
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        if (ds->findUltimateParent(u) != ds->findUltimateParent(v)){
            mcst.push_back(edges[i]);
            ds->unionBySize(u, v);
            cost = cost + w;
        }
    }

    cout << "MCST [format: (u, v, w)]: " << endl;
    for (auto it : mcst){
        int u = it[0], v = it[1], w = it[2];
        cout << "(" << u << ", " << v << ", " << w << ")      ";
    }

    cout << endl << "Cost: " << cost;
}