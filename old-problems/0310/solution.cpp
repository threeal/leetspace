#include <list>
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
    if (n == 1) return {0};

    std::vector<std::list<int>> nextsOf(n);
    std::vector<int> nextsCountOf(n, 0);
    for (const auto& edge : edges) {
      nextsOf[edge[0]].push_back(edge[1]);
      ++nextsCountOf[edge[0]];

      nextsOf[edge[1]].push_back(edge[0]);
      ++nextsCountOf[edge[1]];
    }

    std::queue<int> queue{};
    int visitedNodes{0};

    for (int node{0}; node < n; ++node) {
      if (nextsCountOf[node] == 1) {
        queue.push(node);
        ++visitedNodes;
      }
    }

    while (!queue.empty()) {
      if (visitedNodes == n) {
        std::vector<int> res{};
        while (!queue.empty()) {
          res.push_back(queue.front());
          queue.pop();
        }
        return res;
      }

      for (auto i{queue.size()}; i > 0; --i) {
        const auto node{queue.front()};
        for (const auto next : nextsOf[node]) {
          if (--nextsCountOf[next] == 1) {
            queue.push(next);
            ++visitedNodes;
          }
        }
        queue.pop();
      }
    }

    return {};
  }
};
