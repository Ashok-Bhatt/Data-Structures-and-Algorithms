#include <bits/stdc++.h>
using namespace std;

class Graph{

    public:
    int nodes, edges;
    vector<pair<int,int>> edge_list;
    bool isDirected;
    unordered_map<int, vector<int>> adj_list;

    Graph(int nodes, int edges, vector<pair<int,int>> edge_list, bool isDirected){
        this->nodes = nodes;
        this->edges = edges;
        this->edge_list = edge_list;
        this->isDirected = isDirected;
    }

    void create_adj_list(vector<pair<int,int>> edge_list){

        for (auto i:edge_list){
            adj_list[i.first].push_back(i.second);
            if (this->isDirected){
                adj_list[i.second].push_back(i.first);
            }
        }
    }

    void print_adj_list(unordered_map<int, vector<int>> &adj_list){

        for (auto list:adj_list){
            cout << list.first << "-----> ";
            for (auto element:list.second){
                cout << element << " ";
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
    g1->create_adj_list(edge_list);
    g1->print_adj_list(g1->adj_list);

    delete g1;

    return 0;
}