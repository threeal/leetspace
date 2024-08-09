#include <limits>
#include <list>
#include <vector>

class Solution {
 public:
  int mostProfitablePath(
      std::vector<std::vector<int>>& edges, int bob,
      std::vector<int>& amount) {
    std::vector<std::list<int>> neighbors(amount.size());
    for (const auto& edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }

    exploreBob(neighbors.data(), amount.data(), -1, bob, 0);
    return exploreAlice(neighbors.data(), amount.data(), -1, 0);
  }

  int exploreBob(
      std::list<int>* neighbors, int* amount, int prev, int node, int depth) {
    for (const auto child : neighbors[node]) {
      if (child == prev) continue;
      const int zeroDepth = child != 0
          ? exploreBob(neighbors, amount, node, child, depth + 1)
          : 1;

      if (zeroDepth >= 0) {
        if (depth < zeroDepth) {
          amount[node] = 0;
        } else if (depth == zeroDepth) {
          amount[node] /= 2;
        }
        return 1 + zeroDepth;
      }
    }

    return -1;
  }

  int exploreAlice(std::list<int>* neighbors, int* amount, int prev, int node) {
    int maxProfit{std::numeric_limits<int>::min()};
    for (const auto child : neighbors[node]) {
      if (child == prev) continue;
      const auto profit = exploreAlice(neighbors, amount, node, child);
      if (profit > maxProfit) maxProfit = profit;
    }

    if (maxProfit == std::numeric_limits<int>::min()) maxProfit = 0;
    return amount[node] + maxProfit;
  }
};
