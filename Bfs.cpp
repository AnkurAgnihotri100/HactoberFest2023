#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS and find the shortest path
vector<int> shortestPathBFS(vector<vector<int>>& graph, int start, int end) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    vector<int> parent(numNodes, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    // Reconstruct the shortest path from 'end' to 'start'
    vector<int> shortestPath;
    if (visited[end]) {
        int current = end;
        while (current != -1) {
            shortestPath.push_back(current);
            current = parent[current];
        }
        reverse(shortestPath.begin(), shortestPath.end());
    }

    return shortestPath;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming an undirected graph
    }

    int start, end;
    cout << "Enter the start and end nodes: ";
    cin >> start >> end;

    vector<int> shortestPath = shortestPathBFS(graph, start, end);

    if (!shortestPath.empty()) {
        cout << "Shortest path from " << start << " to " << end << " is: ";
        for (int node : shortestPath) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path from " << start << " to " << end << " exists." << endl;
    }

    return 0;
}
