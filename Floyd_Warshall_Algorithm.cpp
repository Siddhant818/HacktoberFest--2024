#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 1e9;  // Representing infinity (a large value)

void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    
    // Distance matrix initialized with the given graph's weights
    vector<vector<int>> dist = graph;

    // Floyd-Warshall Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << setw(5) << "INF";  // If there's no path, print "INF"
            else
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (use " << INF << " for no direct path):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Run the Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}
