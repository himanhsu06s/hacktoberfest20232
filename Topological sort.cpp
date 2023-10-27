#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Depth-first search helper function
void topologicalSortUtil(int node, vector<bool>& visited, vector<vector<int>>& graph, stack<int>& result) {
    visited[node] = true;
    for (int i : graph[node]) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, graph, result);
        }
    }
    result.push(node);
}

// Topological sort function
void topologicalSort(vector<vector<int>>& graph, int numNodes) {
    vector<bool> visited(numNodes, false);
    stack<int> result;

    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, graph, result);
        }
    }

    // Print the result
    cout << "Topological Sort: ";
    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;
}

int main() {
    // Example graph representation
    vector<vector<int>> graph = {{1, 2}, {3}, {3, 4}, {4}, {5}, {}};
    int numNodes = 6;

    // Perform topological sort
    topologicalSort(graph, numNodes);

    return 0;
}
