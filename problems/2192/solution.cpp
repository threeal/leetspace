#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> getAncestors(
      int n, std::vector<std::vector<int>>& edges) {
    std::sort(
        edges.begin(), edges.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) {
          return a[1] < b[1];
        });

    std::vector<int> indexes(n, -1);
    for (int i = edges.size() - 1; i >= 0; --i) {
      if (indexes[edges[i][1]] == -1) indexes[edges[i][1]] = i;
    }

    std::vector<std::unordered_set<int>> ancestors(n, std::unordered_set<int>{});
    std::vector<bool> collected(n, false);

    for (int i = n - 1; i >= 0; --i) {
      if (collected[i]) continue;
      collectAncestors(
          ancestors, edges.data(), indexes.data(), collected, i);
    }

    std::vector<std::vector<int>> output(n, std::vector<int>{});
    for (int i = n - 1; i >= 0; --i) {
      output[i].reserve(ancestors[i].size());
      for (const auto ancestor : ancestors[i]) {
        output[i].push_back(ancestor);
      }
      std::sort(output[i].begin(), output[i].end());
    }

    return output;
  }

  void collectAncestors(
      std::vector<std::unordered_set<int>>& ancestors,
      std::vector<int>* edges,
      int* indexes,
      std::vector<bool>& collected,
      int i) {
    collected[i] = true;
    for (int j = indexes[i]; j >= 0 && edges[j][1] == i; --j) {
      ancestors[i].insert(edges[j][0]);
      if (!collected[edges[j][0]])
        collectAncestors(ancestors, edges, indexes, collected, edges[j][0]);
      for (const auto ancestor : ancestors[edges[j][0]]) {
        ancestors[i].insert(ancestor);
      }
    }
  }
};
