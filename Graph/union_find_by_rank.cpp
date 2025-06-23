#include <bits/stdc++.h>
using namespace std;

class DisJointSet{
    
    vector<int> ranks, parent;

    public:
    DisJointSet(int n){
        ranks.resize(n, 0);
        parent.resize(n);
        for (int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int x){
        if (x == parent[x]){
            return x;
        } else {
            return parent[x] = findUltimateParent(parent[x]);
        }
    }

    void unionByRank(int u, int v){

        int upar_u = findUltimateParent(u), upar_v = findUltimateParent(v);

        if (upar_u == upar_v){
            return;
        } else if (ranks[upar_u] > ranks[upar_v]){
            parent[upar_v] = upar_u;
        } else if (ranks[upar_u] < ranks[upar_v]){
            parent[upar_u] = upar_v;
        } else {
            parent[upar_v] = upar_u;
            ranks[upar_u]++;
        }
    }

};

int main(){
    
    DisJointSet* ds = new DisJointSet(7);

    ds->unionByRank(1,2);
    ds->unionByRank(3,2);
    ds->unionByRank(4,5);
    ds->unionByRank(6,7);
    ds->unionByRank(5,6);
    if (ds->findUltimateParent(3) == ds->findUltimateParent(7)){
        cout << "3 and 7 are in same components." << endl;
    } else {
        cout << "3 and 7 are not in same components." << endl;
    }
    ds->unionByRank(3,7);
    if (ds->findUltimateParent(3) == ds->findUltimateParent(7)){
        cout << "3 and 7 are in same components." << endl;
    } else {
        cout << "3 and 7 are not in same components." << endl;
    }
}