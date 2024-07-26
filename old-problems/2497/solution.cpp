#include <queue>
#include <vector>

class Solution {
 public:
  int maxStarSum(
      std::vector<int>& vals, std::vector<std::vector<int>>& edges, int k) {
    std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>>
        neighbors(vals.size());

    for (const auto& edge : edges) {
      if (vals[edge[1]] > 0) {
        neighbors[edge[0]].push(vals[edge[1]]);
        if (neighbors[edge[0]].size() > static_cast<std::size_t>(k)) {
          neighbors[edge[0]].pop();
        }
      }

      if (vals[edge[0]] > 0) {
        neighbors[edge[1]].push(vals[edge[0]]);
        if (neighbors[edge[1]].size() > static_cast<std::size_t>(k)) {
          neighbors[edge[1]].pop();
        }
      }
    }

    int maxSum{-10001};
    for (int i = vals.size() - 1; i >= 0; --i) {
      int sum = vals[i];
      while (!neighbors[i].empty()) {
        sum += neighbors[i].top();
        neighbors[i].pop();
      }
      if (maxSum < sum) maxSum = sum;
    }

    return maxSum;
  }
};
