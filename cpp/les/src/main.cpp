#include "FileRaii.h"
#include "Shape.h"
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

using namespace std;

class Data {
public:
  Data(int v) : value(v) { std::cout << "Data created: " << value << "\n"; }
  ~Data() { std::cout << "Data destroyed: " << value << "\n"; }

  int value;
};

struct Graph {
  std::vector<std::vector<int>> adj;
  int V;

  void addEdge(int u, int v) {
    if (u >= 0 && u < V && v >= 0 && v < V) {
      adj[u].push_back(v);
    };
  }

  vector<int> top_sotr() {
    vector<int> inDegree(V, 0);
    vector<int> result;

    for (int i = 0; i < V; i++) {
      for (int nei : adj[i]) {
        inDegree[nei]++;
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
};

int main() {
  auto p = std::make_shared<Data>(21);

  auto p2 = p;
  auto p3 = p2;

  cout << p.use_count() << endl;

  return 0;
}
