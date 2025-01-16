#include <list>
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

    return splitOrMerge(leaves.data(), values.data(), k, -1, 0);
  }

 private:
  static int splitOrMerge(
      std::list<int>* leaves, int* values, int k, int parent, int node) {
    int count{0};
    for (const auto leaf : leaves[node]) {
      if (leaf == parent) continue;
      count += splitOrMerge(leaves, values, k, node, leaf);
    }

    if (values[node] % k == 0) {
      ++count;
    } else if (parent >= 0) {
      values[parent] = (values[parent] + values[node]) % k;
    }

    return count;
  }
};
