#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool validPath(int /*n*/, std::vector<std::vector<int>>& edges, int source, int destination) {
    if (source == destination) return true;

    std::unordered_map<int, std::list<int>> connections{};
    for (const auto& edge : edges) {
      connections[edge[0]].push_back(edge[1]);
      connections[edge[1]].push_back(edge[0]);
    }

    std::unordered_set<int> visited{};
    visited.insert(source);

    std::queue<int> queue;
    queue.push(source);

    while (!queue.empty()) {
      for (const auto next : connections[queue.front()]) {
        if (next == destination) return true;
        if (!visited.contains(next)) {
          visited.insert(next);
          queue.push(next);
        }
      }
      queue.pop();
    }

    return false;
  }
};
