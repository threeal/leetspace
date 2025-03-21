#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> minimumCost(
      int n, std::vector<std::vector<int>>& edges,
      std::vector<std::vector<int>>& query) {
    std::vector<int> roots(n);
    std::iota(roots.begin(), roots.end(), 0);

    std::vector<int> rootSizes(n, 1);
    std::vector<int> rootCosts(n, ~0);

    for (const auto& edge : edges) {
      const int root0{findRoot(roots, edge[0])};
      const int root1{findRoot(roots, edge[1])};
      if (root0 == root1) {
        rootCosts[root0] &= edge[2];
      } else {
        if (rootSizes[root0] >= rootSizes[root1]) {
          roots[root1] = root0;
          rootSizes[root0] += rootSizes[root1];
          rootCosts[root0] &= rootCosts[root1] & edge[2];
        } else {
          roots[root0] = root1;
          rootSizes[root1] += rootSizes[root0];
          rootCosts[root1] &= rootCosts[root0] & edge[2];
        }
      }
    }

    std::vector<int> output(query.size());
    for (std::size_t i{0}; i < query.size(); ++i) {
      const int root0{findRoot(roots, query[i][0])};
      output[i] = root0 == findRoot(roots, query[i][1]) ? rootCosts[root0] : -1;
    }

    return output;
  }

 private:
  static int findRoot(std::vector<int>& roots, int n) {
    return roots[n] == n ? n : (roots[n] = findRoot(roots, roots[n]));
  }
};
