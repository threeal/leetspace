#include <vector>

class Solution {
 public:
  int assignEdgeWeights(std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> nexts(edges.size() + 1);
    for (const auto& edge : edges) {
      nexts[edge[0] - 1].push_back(edge[1] - 1);
      nexts[edge[1] - 1].push_back(edge[0] - 1);
    }

    int depth{findMaxDepth(nexts, -1, 0) - 1};

    long long res{1}, base{2};
    while (depth != 0) {
      if (depth % 2 != 0) res = res * base % 1000000007;
      base = base * base % 1000000007;
      depth /= 2;
    }

    return res;
  }

 private:
  static int findMaxDepth(
      const std::vector<std::vector<int>>& nexts,
      int prev, int node) {
    int maxDepth{0};
    for (const int next : nexts[node]) {
      if (next != prev) {
        const int depth{1 + findMaxDepth(nexts, node, next)};
        if (depth > maxDepth) maxDepth = depth;
      }
    }
    return maxDepth;
  }
};
