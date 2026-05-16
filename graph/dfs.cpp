#include <iostream>
#include <vector>

using namespace std;

void dfsHelper(vector<vector<int>>& graph, int node, vector<bool>& visited) {

    visited[node] = true;

    cout << node << " ";

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {
            dfsHelper(graph, neighbor, visited);
        }
    }
}

void dfs(vector<vector<int>>& graph, int start) {

    int n = graph.size();

    vector<bool> visited(n, false);

    dfsHelper(graph, start, visited);

    cout << "\n";
}

int main() {

    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1, 5},
        {2, 4}
    };

    dfs(graph, 0);

    return 0;
}