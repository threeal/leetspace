#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<bool> areConnected(
      int n, int threshold, std::vector<std::vector<int>>& queries) {
    std::vector<int> roots(n + 1);
    std::iota(roots.begin(), roots.end(), 0);

    std::vector<int> rootSizes(n + 1, 1);
    for (int a{threshold + 1}; a <= n; ++a) {
      int rootA{findRoot(roots, a)};
      for (int b{a + a}; b <= n; b += a) {
        const int rootB{findRoot(roots, b)};
        if (rootSizes[rootA] < rootSizes[rootB]) rootA = rootB;
      }

      for (int b{a}; b <= n; b += a) {
        const int rootB{findRoot(roots, b)};
        if (rootB != rootA) {
          roots[rootB] = rootA;
          rootSizes[rootA] += rootSizes[rootB];
        }
      }
    }

    std::vector<bool> outputs(queries.size());
    for (std::size_t i{0}; i < queries.size(); ++i) {
      outputs[i] =
          findRoot(roots, queries[i][0]) == findRoot(roots, queries[i][1]);
    }

    return outputs;
  }

 private:
  static int findRoot(std::vector<int>& roots, int n) {
    return roots[n] == n ? n : roots[n] = findRoot(roots, roots[n]);
  }
};
