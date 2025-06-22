#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void dijkstra(vector<vector<int> > &cost, int start, int end, int n) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    dist[start] = 0;

    for (int count = 0; count < n - 1; ++count) {
        int u = -1, minDist = INF;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (cost[u][v] != 0 && !visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nCost List:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jalur Terpendek:\n";
    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.insert(path.begin(), v);
    }

    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] + 1;
        if (i != path.size() - 1) cout << "--->";
    }

    cout << "\nMinimum Cost: " << dist[end] << endl;
}

int main() {
    int n;
    cout << "Masukkan Jumlah Kota: ";
    cin >> n;

    vector<vector<int> > cost(n, vector<int>(n));
    cout << "Nilai COST Matrix:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Cost Element Baris ke-" << i + 1 << " : ";
        cout << endl;
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
        cout << endl;
    }

    int start, end;
    cout << "\nMasukkan Kota Awal (1-" << n << "): ";
    cin >> start;
    cout << "Masukkan Kota Tujuan (1-" << n << "): ";
    cin >> end;

    dijkstra(cost, start - 1, end - 1, n);

    return 0;
}
