#include <bits/stdc++.h>
using namespace std;

class Graph{

    public:
    int nodes, edges;
    vector<pair<int,int>> edge_list;
    bool isDirected;
    vector<vector<int>> adj_matrix;

    Graph(int nodes, int edges, vector<pair<int,int>> edge_list, bool isDirected){
        this->nodes = nodes;
        this->edges = edges;
        this->edge_list = edge_list;
        this->isDirected = isDirected;
        this->adj_matrix.resize(this->nodes, vector<int>(this->nodes, 0));
    }

    void create_adj_matrix(vector<pair<int,int>> edge_list){

        for (auto i:edge_list){
            adj_matrix[i.first][i.second] = 1;
            if (this->isDirected){
                adj_matrix[i.second][i.first] = 1;
            }
        }
    }

    void print_adj_matrix(vector<vector<int>> &adj_matrix){

        for (int i=0; i<this->nodes; i++){
            for (int j=0; j<this->nodes; j++){
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){

    int nodes = INT_MIN;
    int edges = 5;
    vector<pair<int,int>> edge_list;

    cout << "Enter edge list: " << endl;
    for (int i=0; i<edges; i++){
       pair<int,int> p1;
       cin >> p1.first;
       cin >> p1.second;
       edge_list.push_back(p1);
       nodes = max(nodes, max(p1.first, p1.second));
    }
    
    Graph* g1 = new Graph(nodes, edges, edge_list, false);
    g1->create_adj_matrix(edge_list);
    g1->print_adj_matrix(g1->adj_matrix);

    delete g1;

    return 0;
}