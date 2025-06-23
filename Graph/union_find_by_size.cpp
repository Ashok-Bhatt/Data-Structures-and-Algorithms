#include<bits/stdc++.h>
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
            size[upar_v] = size[upar_v] + size[upar_u];
        } else {
            parent[upar_u] = upar_v;
            size[upar_u] = size[upar_u] + size[upar_v];
        }
    }
};

int main(){
    DisJointSet* ds = new DisJointSet(7);

    ds->unionBySize(1,2);
    ds->unionBySize(3,2);
    ds->unionBySize(4,5);
    ds->unionBySize(6,7);
    ds->unionBySize(5,6);
    if (ds->findUltimateParent(5) == ds->findUltimateParent(6)){
        cout << "5 and 6 are in same components." << endl;
    } else {
        cout << "5 and 6 are not in same components." << endl;
    }
    ds->unionBySize(3,7);
    if (ds->findUltimateParent(3) == ds->findUltimateParent(7)){
        cout << "3 and 7 are in same components." << endl;
    } else {
        cout << "3 and 7 are not in same components." << endl;
    }
}