#include <iostream>
using namespace std;
class Graph {
private:
    int V; 
    int** adj;

public:
    Graph(int vertices) {
        V = vertices;

        adj = new int*[V];
        for (int i = 0; i < V; ++i) {
            adj[i] = new int[V];
            for (int j = 0; j < V; ++j) {
                adj[i][j] = 0;
            }
        }
    }
    ~Graph() {
        for (int i = 0; i < V; ++i) {
            delete[] adj[i];
        }
        delete[] adj;
    }

    
    void insertEdge(int u, int v) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Error: vertex index out of bounds" << endl;
            return;
        }
        adj[u][v] = 1;
    }

    
    void DFSUtil(int vertex, bool* visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < V; ++i) {
            if (adj[vertex][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    
    void DFS(int start) {
        if (start < 0 || start >= V) {
            cout << "Error: start vertex index out of bounds" << endl;
            return;
        }
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i)
            visited[i] = false;

        DFSUtil(start, visited);

        delete[] visited;
    }
};

int main() {
    int vertices = 5;
    Graph g(vertices);
    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 3);
    g.insertEdge(1, 4);
    g.insertEdge(2, 4);
    cout << "DFS traversal starting from vertex 0:" << endl;
    g.DFS(0);
    cout << endl;
    return 0;
}

