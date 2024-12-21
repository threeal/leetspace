#include <list>
#include <tuple>
#include <vector>

class Solution {
 public:
  int maxKDivisibleComponents(
      int n, std::vector<std::vector<int>>& edges,
      std::vector<int>& values, int k) {
    std::vector<std::list<int>> leaves(n);
    for (const auto& edge : edges) {
      leaves[edge[0]].push_back(edge[1]);
      leaves[edge[1]].push_back(edge[0]);
    }

    const auto [count, sum] = splitOrMerge(leaves, values, k, -1, 0);
    return count;
  }

 private:
  static std::tuple<int, int> splitOrMerge(
      const std::vector<std::list<int>>& leaves,
      const std::vector<int>& values, int k, int parent, int node) {
    int count{0}, sum{values[node] % k};

    for (const auto leaf : leaves[node]) {
      if (leaf == parent) continue;
      const auto [leafCount, leafSum] = splitOrMerge(leaves, values, k, node, leaf);
      count += leafCount;
      sum = (sum + leafSum) % k;
    }

    if (sum % k == 0) {
      return {count + 1, 0};
    } else {
      return {count, sum};
    }
  }
};
