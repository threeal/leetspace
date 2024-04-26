#include <list>
#include <queue>
#include <vector>

class Solution {
 public:
  bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    if (source == destination) return true;

    std::vector<std::list<int>> connections(n);
    for (const auto& edge : edges) {
      connections[edge[0]].push_back(edge[1]);
      connections[edge[1]].push_back(edge[0]);
    }

    std::vector<bool> visited(n, false);
    visited[source] = true;

    std::queue<int> queue;
    queue.push(source);

    while (!queue.empty()) {
      for (const auto next : connections[queue.front()]) {
        if (next == destination) return true;
        if (!visited[next]) {
          visited[next] = true;
          queue.push(next);
        }
      }
      queue.pop();
    }

    return false;
  }
};
