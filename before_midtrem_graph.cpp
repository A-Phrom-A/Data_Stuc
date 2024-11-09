#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

// Node structure for the adjacency list
struct Node {
    int dest;
    int weight; // ??????????????????????

    Node(int d, int w = 1) : dest(d), weight(w) {}
};

class Graph {
public:
    int numVertices;
    vector< list<Node> > adjList;
    bool directed; // ?????????????????????????

    Graph(int V) : numVertices(V), adjList(V), directed(false) {} // ???????????????????????

    void addEdge(int src, int dest, int weight = 1) {
        adjList[src].push_back(Node(dest, weight));
        if (!directed) { // ????????????????????????????????????????
            adjList[dest].push_back(Node(src, weight));
        }
    }

    void visualize() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            // ?????????? range-based loop ???? loop ???????????
            for (list<Node>::iterator it = adjList[i].begin(); it != adjList[i].end(); ++it) {
                cout << it->dest << "(" << it->weight << ") ";
            }
            cout << endl;
        }
    }

    void bfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " "; // ????????????

            for (list<Node>::iterator it = adjList[current].begin(); it != adjList[current].end(); ++it) {
                if (!visited[it->dest]) {
                    visited[it->dest] = true;
                    q.push(it->dest);
                }
            }
        }
    }

    void dfsHelper(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " "; // ????????????

        for (list<Node>::iterator it = adjList[vertex].begin(); it != adjList[vertex].end(); ++it) {
            if (!visited[it->dest]) {
                dfsHelper(it->dest, visited);
            }
        }
    }

    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        dfsHelper(startVertex, visited);
    }
};

int main() {
    Graph graph(5); // ?????????????? 5 ????

    // ???????? (?????????????????????????)
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Adjacency List Representation:\n";
    graph.visualize();

    int startNode = 0;

    cout << "BFS Traversal starting from vertex " << startNode << ": ";
    graph.bfs(startNode);
    cout << endl;

    cout << "DFS Traversal starting from vertex " << startNode << ": ";
    graph.dfs(startNode);
    cout << endl;

    return 0;
}

