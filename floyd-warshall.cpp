#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const int INF = 1e9; 

void floydWarshall(vector<vector<int>>& graph) {
    int numVertices = graph.size();
    
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    
    for (int i = 0; i < numVertices; ++i) {
        if (graph[i][i] < 0) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    cout << "Shortest distance matrix between every pair of vertices:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (graph[i][j] == INF) {
                cout << setw(5) << "INF";
            } else {
                cout << setw(5) << graph[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}
