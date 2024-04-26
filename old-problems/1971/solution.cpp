#include <vector>

class Solution {
 public:
  bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    if (source == destination) return true;

    std::vector<bool> visited(n, false);
    visited[source] = true;

    bool valid{true};
    while (valid) {
      valid = false;
      for (const auto& edge : edges) {
        if (visited[edge[0]] != visited[edge[1]]) {
          visited[edge[0]] = true;
          visited[edge[1]] = true;
          valid = true;
        }
      }
      if (visited[destination]) return true;
    }

    return false;
  }
};
