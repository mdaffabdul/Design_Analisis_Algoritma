#include <iostream>
#include <vector>
using namespace std;

class DirectedGraph {
private:
    int V;
    vector<vector<int> > adj;

public:
    DirectedGraph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void printGraph() {
        cout << "Representasi Adjacency List dari Graf Berarah:" << endl;
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
    DirectedGraph dg(5);

    cout << "Menambahkan sisi ke Graf Berarah..." << endl;
    dg.addEdge(0, 1);
    dg.addEdge(0, 4);
    dg.addEdge(1, 2);
    dg.addEdge(3, 1); 
    dg.addEdge(4, 1); 
    dg.addEdge(2, 3); 
    dg.addEdge(4, 3); 

    cout << endl;
    dg.printGraph();

    return 0;
}
