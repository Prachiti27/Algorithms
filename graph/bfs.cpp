#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {

    int n = graph.size();

    vector<bool> visited(n, false);

    queue<int> q;

    q.push(start);

    visited[start] = true;

    while (!q.empty()) {

        int node = q.front();

        q.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {

            if (!visited[neighbor]) {

                visited[neighbor] = true;

                q.push(neighbor);
            }
        }
    }

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

    bfs(graph, 0);

    return 0;
}