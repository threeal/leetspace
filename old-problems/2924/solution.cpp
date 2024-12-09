#include <vector>

class Solution {
 public:
  int findChampion(int n, std::vector<std::vector<int>>& edges) {
    std::vector<bool> isChild(n, false);
    for (const auto& edge : edges) {
      isChild[edge[1]] = true;
    }

    int parent{-1};
    for (int i{0}; i < n; ++i) {
      if (!isChild[i]) {
        if (parent >= 0) return -1;
        parent = i;
      }
    }

    return parent;
  }
};
