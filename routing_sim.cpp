#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

const int INF = 9999;

void printDVRTable(int node, const vector<vector<int>>& table, const vector<vector<int>>& nextHop) {
    cout << "Node " << node << " Routing Table:\n";
    cout << "Dest\tCost\tNext Hop\n";
    for (int i = 0; i < table.size(); ++i) {
        cout << i << "\t" << table[node][i] << "\t";
        if (nextHop[node][i] == -1) cout << "-";
        else cout << nextHop[node][i];
        cout << endl;
    }
    cout << endl;
}

void simulateDVR(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph;
    vector<vector<int>> nextHop(n, vector<int>(n));

    //TODO: Complete this
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            nextHop[i][j] = (graph[i][j] != 0 && graph[i][j] != INF && i != j) ? j : -1;

    bool updated;
    do {
        updated = false;
        for (int i = 0; i < n; ++i) {           // For each node
            for (int j = 0; j < n; ++j) {       // Destination
                for (int k = 0; k < n; ++k) {   // Neighbor
                    if (graph[i][k] != INF && dist[k][j] != INF) {
                        int newCost = graph[i][k] + dist[k][j];
                        if (newCost < dist[i][j]) {
                            dist[i][j] = newCost;
                            nextHop[i][j] = k;
                            updated = true;
                        }
                    }
                }
            }
        }
    } while (updated);

    cout << "--- DVR Final Tables ---\n";
    for (int i = 0; i < n; ++i) printDVRTable(i, dist, nextHop);
}

void printLSRTable(int src, const vector<int>& dist, const vector<int>& prev) {
    cout << "Node " << src << " Routing Table:\n";
    cout << "Dest\tCost\tNext Hop\n";
    for (int i = 0; i < dist.size(); ++i) {
        if (i == src) continue;
        cout << i << "\t" << dist[i] << "\t";
        int hop = i;
        while (prev[hop] != src && prev[hop] != -1)
            hop = prev[hop];
        cout << (prev[hop] == -1 ? -1 : hop) << endl;
    }
    cout << endl;
}

void simulateLSR(const vector<vector<int>>& graph) {
    int n = graph.size();
    for (int src = 0; src < n; ++src) {
        vector<int> dist(n, INF);
        vector<int> prev(n, -1);
        vector<bool> visited(n, false);
        dist[src] = 0;
        
         //TODO: Complete this
                 for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int j = 0; j < n; ++j)
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;

            if (dist[u] == INF) break;
            visited[u] = true;

            for (int v = 0; v < n; ++v) {
                if (graph[u][v] != 0 && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    prev[v] = u;
                }
            }
        }
        
        printLSRTable(src, dist, prev);
    }
}

vector<vector<int>> readGraphFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }
    
    int n;
    file >> n;
    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            file >> graph[i][j];

    file.close();
    return graph;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    string filename = argv[1];
    vector<vector<int>> graph = readGraphFromFile(filename);

    cout << "\n--- Distance Vector Routing Simulation ---\n";
    simulateDVR(graph);

    cout << "\n--- Link State Routing Simulation ---\n";
    simulateLSR(graph);

    return 0;
}

