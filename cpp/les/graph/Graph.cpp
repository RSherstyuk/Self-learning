#include "Graph.h"

Graph::Graph(int ver) : V(ver) { adj.resize(V); }

void Graph::addEdge(int u, int v) {
  if (u >= 0 && u < V && v >= 0 && v < V) {
    adj[u].push_back(v);
  }
}

std::vector<int> Graph::topologicalSort() {
  std::vector<int> inDegree(V, 0);
  std::vector<int> result;

  // Вычисляем входящие степени вершин
  for (int i = 0; i < V; i++) {
    for (int neighbor : adj[i]) {
      inDegree[neighbor]++;
    }
  }

  std::queue<int> q;
  for (int i = 0; i < V; i++) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }

  int count = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    result.push_back(u);

    for (int v : adj[u]) {
      inDegree[v]--;
      if (inDegree[v] == 0) {
        q.push(v);
      }
    }

    count++;
  }

  if (count != V) {
    std::cout << "Graph has a cycle" << std::endl;
    return {};
  }

  return result;
}
