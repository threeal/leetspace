#include <numeric>
#include <vector>

class Solution {
 public:
  int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
    std::vector<int> roots(n);
    std::iota(roots.begin(), roots.end(), 0);

    std::vector<int> rootNodes(n, 1);
    std::vector<int> rootEdges(n, 0);

    for (const auto& edge : edges) {
      const int root0{findRoot(roots, edge[0])};
      const int root1{findRoot(roots, edge[1])};

      if (root0 == root1) {
        ++rootEdges[root0];
      } else {
        if (rootNodes[root0] >= rootNodes[root1]) {
          roots[root1] = root0;
          rootNodes[root0] += rootNodes[root1];
          rootEdges[root0] += 1 + rootEdges[root1];
        } else {
          roots[root0] = root1;
          rootNodes[root1] += rootNodes[root0];
          rootEdges[root1] += 1 + rootEdges[root0];
        }
      }
    }

    int count{0};
    for (int i{0}; i < n; ++i) {
      if (roots[i] == i &&
          rootEdges[i] == (rootNodes[i] * (rootNodes[i] - 1)) / 2) {
        ++count;
      }
    }

    return count;
  }

 private:
  static int findRoot(std::vector<int>& roots, int i) {
    return roots[i] == i ? i : (roots[i] = findRoot(roots, roots[i]));
  }
};
