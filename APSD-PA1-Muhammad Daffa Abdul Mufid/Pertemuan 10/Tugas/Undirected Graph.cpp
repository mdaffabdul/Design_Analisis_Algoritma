#include <iostream>
#include <vector>
using namespace std;

class UndirectedGraph {
private:
    int V;
    vector<vector<int> > adj;

public:
    UndirectedGraph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printGraph() {
        cout << "Representasi Adjacency List dari Graf Tidak Berarah:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Simpul " << i << ":";
            for (size_t j = 0; j < adj[i].size(); ++j) {
                cout << " -> " << adj[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    UndirectedGraph ug(5);

    cout << "Menambahkan sisi ke Graf Tidak Berarah..." << endl;
    ug.addEdge(0, 1);
    ug.addEdge(0, 4);
    ug.addEdge(1, 2);
    ug.addEdge(1, 3);
    ug.addEdge(1, 4);
    ug.addEdge(2, 3);
    ug.addEdge(3, 4);

    cout << endl;
    ug.printGraph();

    return 0;
}
