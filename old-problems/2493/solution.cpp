#include <numeric>
#include <queue>
#include <vector>

class Solution {
 public:
  int magnificentSets(int n, std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> neighbors(n + 1);
    std::vector<int> roots(n + 1), rootSizes(n + 1, 1);
    std::iota(roots.begin(), roots.end(), 0);

    for (const auto& edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);

      int root0{findRoot(roots, edge[0])};
      int root1{findRoot(roots, edge[1])};
      if (root0 != root1) {
        if (rootSizes[root0] >= rootSizes[root1]) {
          roots[root1] = root0;
          rootSizes[root0] += rootSizes[root1];
        } else {
          roots[root0] = root1;
          rootSizes[root1] += rootSizes[root0];
        }
      }
    }

    std::vector<int> rootGroups(n + 1, 0);
    for (int node{1}; node <= n; ++node) {
      std::vector<int> nodeDepths(n + 1, 0);
      nodeDepths[node] = 1;

      std::queue<int> nodes({node});
      int depth{2};
      while (!nodes.empty()) {
        for (std::size_t n{nodes.size()}; n > 0; --n) {
          auto node = nodes.front();
          nodes.pop();

          for (const auto neighbor : neighbors[node]) {
            if (nodeDepths[neighbor] == 0) {
              nodeDepths[neighbor] = depth;
              nodes.push(neighbor);
            } else if (nodeDepths[neighbor] != depth &&
                       nodeDepths[neighbor] != depth - 2) {
              return -1;
            }
          }
        }
        ++depth;
      }

      int root{findRoot(roots, node)};
      if (depth - 2 > rootGroups[root]) rootGroups[root] = depth - 2;
    }

    return std::accumulate(rootGroups.begin(), rootGroups.end(), 0);
  }

 private:
  static int findRoot(std::vector<int>& roots, int n) {
    return roots[n] == n ? n : (roots[n] = findRoot(roots, roots[n]));
  }
};
