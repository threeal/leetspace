#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> findRedundantConnection(
      std::vector<std::vector<int>>& edges) {
    std::vector<int> roots(edges.size() + 1);
    std::iota(roots.begin(), roots.end(), 0);

    std::vector<int> rootSizes(edges.size() + 1, 1);
    for (const auto& edge : edges) {
      const auto a = findRoot(roots, edge[0]);
      const auto b = findRoot(roots, edge[1]);
      if (a == b) return edge;
      if (rootSizes[a] <= rootSizes[b]) {
        roots[b] = a;
        rootSizes[a] += rootSizes[b];
      } else {
        roots[a] = b;
        rootSizes[b] += rootSizes[a];
      }
    }

    return edges.front();
  }

 private:
  static int findRoot(std::vector<int>& roots, int node) {
    if (roots[node] == node) return node;
    return roots[node] = findRoot(roots, roots[node]);
  }
};
