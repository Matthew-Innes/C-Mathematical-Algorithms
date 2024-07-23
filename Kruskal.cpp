#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges.resize(E);
    }

    void addEdge(int e, int src, int dest, int weight) {
        edges[e] = {src, dest, weight};
    }

    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void unionSet(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        if (xset != yset)
            parent[xset] = yset;
    }

    void KruskalMST() {
        vector<Edge> result;
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V, -1);
        
        for (auto edge : edges) {
            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);

            if (x != y) {
                result.push_back(edge);
                unionSet(parent, x, y);
            }
        }

        cout << "Edges in the MST using Kruskal's Algorithm:\n";
        for (auto edge : result) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        }
    }
};

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Graph graph(V, E);

    graph.addEdge(0, 0, 1, 10);
    graph.addEdge(1, 0, 2, 6);
    graph.addEdge(2, 0, 3, 5);
    graph.addEdge(3, 1, 3, 15);
    graph.addEdge(4, 2, 3, 4);

    graph.KruskalMST();

    return 0;
}