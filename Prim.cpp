#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adjMatrix;

    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int src, int dest, int weight) {
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
    }

    int minKey(vector<int>& key, vector<bool>& mstSet) {
        int min = INT_MAX, minIndex;
        for (int v = 0; v < V; ++v)
            if (!mstSet[v] && key[v] < min)
                min = key[v], minIndex = v;
        return minIndex;
    }

    void PrimMST() {
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> mstSet(V, false);

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; ++count) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < V; ++v)
                if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v])
                    parent[v] = u, key[v] = adjMatrix[u][v];
        }

        cout << "Edges in the MST using Prim's Algorithm:\n";
        for (int i = 1; i < V; ++i)
            cout << parent[i] << " -- " << i << " == " << adjMatrix[i][parent[i]] << endl;
    }
};

int main() {
    int V = 4; // Number of vertices
    Graph graph(V);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    graph.PrimMST();

    return 0;
}