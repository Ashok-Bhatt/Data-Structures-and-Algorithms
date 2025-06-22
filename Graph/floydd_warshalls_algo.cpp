#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter E: ";
    cin >> e;

    vector<vector<int>> edges(e);
    vector<vector<int>> costMatrix(n, vector<int>(n, (int)1e9));

    for (int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp = {u, v, w};
        edges[i] = temp;
    }

    for (int i=0; i<e; i++){
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        costMatrix[u][v] = w;
    }

    for (int i=0; i<n; i++){
        costMatrix[i][i] = 0;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                costMatrix[j][k] = min(costMatrix[j][k], costMatrix[j][i]+costMatrix[i][k]);
            }
        }
    }

    cout << "Cost Matrix: " << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (costMatrix[i][j] == (int)1e9){
                cout << "- ";
            } else {
                cout << costMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}