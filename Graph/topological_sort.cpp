#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adjList, stack<int> &st){

    for (auto neighbor : adjList[node]){
        if (!visited[neighbor]){
            visited[neighbor] = true;
            dfs(neighbor, visited, adjList, st);
        }
    }

    st.push(node);
}

int main(){

    int n, e;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter e: ";
    cin >> e;

    vector<vector<int>> adjList(n);
    vector<int> ans;
    vector<bool> visited(n, false);
    stack<int> st;
    
    for (int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    for (int i=0; i<n; i++){
        if (!visited[i]){
            visited[i] = true;
            dfs(i, visited, adjList, st);
        }
    }

    cout << endl << "Topological sort ordering: ";
    while (!st.empty()){
        int top = st.top();
        st.pop();
        cout << top << " ";
    }
    cout << endl;
}