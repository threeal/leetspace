#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
    if (n == 1) return {0};

    std::unordered_map<int, std::unordered_set<int>> connections{};
    for (const auto& edge : edges) {
      connections[edge[0]].insert(edge[1]);
      connections[edge[1]].insert(edge[0]);
    }

    std::queue<int> queue{};
    int visited_left{n};

    for (const auto& [node, connection] : connections) {
      if (connection.size() > 1) continue;
      queue.push(node);
      --visited_left;
    }

    while (!queue.empty()) {
      if (visited_left == 0) {
        std::vector<int> res{};
        while (!queue.empty()) {
          res.push_back(queue.front());
          queue.pop();
        }
        return res;
      }

      for (auto i{queue.size()}; i > 0; --i) {
        const auto node{queue.front()};
        const auto next{*connections[node].begin()};
        connections[next].erase(node);
        if (connections[next].size() == 1) {
          queue.push(next);
          --visited_left;
        }
        queue.pop();
      }
    }

    return {};
  }
};
