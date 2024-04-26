#include <vector>

class Solution {
 public:
  bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    if (source == destination) return true;

    std::vector<bool> visited(n, false);
    visited[source] = true;

    std::size_t edgesSize{edges.size()};
    std::size_t prevEdgesSize{edgesSize + 1};
    while (edgesSize != prevEdgesSize) {
      prevEdgesSize = edgesSize;
      for (std::size_t i{0}; i < edgesSize; ++i) {
        if (visited[edges[i][0]] != visited[edges[i][1]]) {
          visited[edges[i][0]] = true;
          visited[edges[i][1]] = true;

          edges[i] = edges[--edgesSize];
          --i;
        }
      }
      if (visited[destination]) return true;
    }

    return false;
  }
};
