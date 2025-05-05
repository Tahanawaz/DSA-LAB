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
            cout << "Error: vertex index out of bounds\n";
            return;
        }
        adj[u][v] = 1;
    }

    void BFS(int start) {
        if (start < 0 || start >= V) {
            cout << "Error: start vertex index out of bounds\n";
            return;
        }

        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i)
            visited[i] = false;
        int* queue = new int[V];

        int front = 0, rear = 0;


        queue[rear++] = start;
        visited[start] = true;

        while (front != rear) {
            int current = queue[front++];
            cout << current << " ";


            for (int i = 0; i < V; ++i) {
                if (adj[current][i] == 1 && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = true;
                }
            }
        }

        cout << endl;
        delete[] visited;
        delete[] queue;
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

    cout << "BFS traversal starting from vertex 0:\n";
    g.BFS(0);

    return 0;
}
