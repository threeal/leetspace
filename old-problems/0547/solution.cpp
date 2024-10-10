#include <numeric>
#include <vector>

class Solution {
 public:
  int findCircleNum(std::vector<std::vector<int>>& isConnected) {
    int distinctCount = isConnected.size();

    std::vector<int> roots(isConnected.size());
    std::iota(roots.begin(), roots.end(), 0);

    for (std::size_t i{0}; i < isConnected.size(); ++i) {
      for (std::size_t j{i + 1}; j < isConnected.size(); ++j) {
        if (isConnected[i][j] == 0) continue;

        int rootI = findRoot(roots.data(), i);
        int rootJ = findRoot(roots.data(), j);
        if (rootI != rootJ) {
          if (rootI > rootJ) std::swap(rootI, rootJ);
          roots[rootI] = rootJ;
          --distinctCount;
        }
      }
    }

    return distinctCount;
  }

 private:
  static int findRoot(int* roots, int i) {
    if (roots[i] != i) roots[i] = findRoot(roots, roots[i]);
    return roots[i];
  }
};
