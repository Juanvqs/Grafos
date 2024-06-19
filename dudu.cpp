#include <iostream>
#include <vector>

using namespace std;

bool hasCycleDFS(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, graph, visited, recStack)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = 0;
    return false;
}

bool hasCycle(int n, vector<vector<int>>& dependencies) {
    vector<vector<int>> graph(n + 1);
    for (const auto& dep : dependencies) {
        graph[dep[0]].push_back(dep[1]);
    }

    vector<int> visited(n + 1, 0);
    vector<int> recStack(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (hasCycleDFS(i, graph, visited, recStack)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> dependencies(M, vector<int>(2));
        for (int i = 0; i < M; ++i) {
            cin >> dependencies[i][0] >> dependencies[i][1];
        }

        if (hasCycle(N, dependencies)) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    }

    return 0;
}