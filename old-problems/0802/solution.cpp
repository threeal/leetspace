#include <vector>

class Solution {
 public:
  std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
    std::vector<bool> isSafeNodes(graph.size(), false);
    for (std::size_t i{0}; i < graph.size(); ++i) {
      if (graph[i].empty()) isSafeNodes[i] = true;
    }

    bool haveNewSafeNode{true};
    while (haveNewSafeNode) {
      haveNewSafeNode = false;
      for (std::size_t i{0}; i < graph.size(); ++i) {
        if (!isSafeNodes[i]) {
          bool allIsSafeNode{true};
          for (const auto next : graph[i]) {
            if (!isSafeNodes[next]) {
              allIsSafeNode = false;
              break;
            }
          }
          if (allIsSafeNode) {
            isSafeNodes[i] = true;
            haveNewSafeNode = true;
          }
        }
      }
    }

    std::vector<int> safeNodes{};
    safeNodes.reserve(isSafeNodes.size());

    for (std::size_t i{0}; i < isSafeNodes.size(); ++i) {
      if (isSafeNodes[i]) safeNodes.push_back(i);
    }

    return safeNodes;
  }
};
