#include<iostream>
#include<list>
#include<queue>
#include<stack>


using namespace std;

class Graph {
    int vertices;
    list<int>* adjList;

public:
    Graph(int v);
    void addEdge(int v, int w);
    void DFS(int startVertex);
    void BFS(int startVertex);
};

Graph::Graph(int v) {
    vertices = v;
    adjList = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

void Graph::DFS(int startVertex) {
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    stack<int> stack;
    visited[startVertex] = true;
    stack.push(startVertex);

    while (!stack.empty()) {
        startVertex = stack.top();
        cout << startVertex << " ";
        stack.pop();

        for (auto i = adjList[startVertex].begin(); i != adjList[startVertex].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                stack.push(*i);
            }
        }
    }

    delete[] visited;
}

void Graph::BFS(int startVertex) {
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    queue<int> queue;
    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        startVertex = queue.front();
        cout << startVertex << " ";
        queue.pop();

        for (auto i = adjList[startVertex].begin(); i != adjList[startVertex].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }

    delete[] visited;
}

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);

    cout << "DFS starting from vertex 0: ";
    graph.DFS(0);

    cout << "\nBFS starting from vertex 0: ";
    graph.BFS(0);

    return 0;
}
