#include <list>
#include <vector>

class Solution {
 public:
  std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges) {
    std::vector<std::list<int>> nexts(n);
    for (const auto& edge : edges) {
      nexts[edge[0]].push_back(edge[1]);
      nexts[edge[1]].push_back(edge[0]);
    }

    std::vector<int> counts(n, 1);
    std::vector<int> sums(n, 0);

    dfsCount(nexts, sums, counts, 0, -1);
    dfsSum(nexts, sums, counts, 0, -1);

    return sums;
  }

 private:
  void dfsCount(const std::vector<std::list<int>>& nexts, std::vector<int>& sums, std::vector<int>& counts, int node, int parent) {
    for (const auto next : nexts[node]) {
      if (next == parent) continue;
      dfsCount(nexts, sums, counts, next, node);
      counts[node] += counts[next];
      sums[node] += counts[next] + sums[next];
    }
  }

  void dfsSum(const std::vector<std::list<int>>& nexts, std::vector<int>& sums, std::vector<int>& counts, int node, int parent) {
    for (const auto next : nexts[node]) {
      if (next == parent) continue;
      sums[next] = sums[node] + counts.size() - counts[next] * 2;
      dfsSum(nexts, sums, counts, next, node);
    }
  }
};
