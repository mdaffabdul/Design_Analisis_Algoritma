#include <iostream>
#include <vector>
#include <utility> 
using namespace std;

class WeightedGraph {
private:
    int V;
    vector<vector<pair<int, int> > > adj;

public:
    WeightedGraph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }

    void printGraph() {
        cout << "Representasi Adjacency List dari Graf Berbobot:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Simpul " << i << ":";
            for (size_t j = 0; j < adj[i].size(); ++j) {
                int neighbor = adj[i][j].first;
                int weight = adj[i][j].second;
                cout << " -> (" << neighbor << ", bobot: " << weight << ")";
            }
            cout << endl;
        }
    }
};

int main() {
    WeightedGraph wg(5);

    cout << "Menambahkan sisi ke Graf Berbobot..." << endl;
    wg.addEdge(0, 1, 10);
    wg.addEdge(0, 4, 20);
    wg.addEdge(1, 2, 30);
    wg.addEdge(1, 3, 40);
    wg.addEdge(1, 4, 50);
    wg.addEdge(2, 3, 60);
    wg.addEdge(3, 4, 70);

    cout << endl;
    wg.printGraph();

    return 0;
}
