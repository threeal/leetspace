#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> allPathsSourceTarget(
      std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> output{};
    std::vector<int> nodes{};
    backtrack(output, graph, nodes, 0, graph.size() - 1);
    return output;
  }

  void backtrack(
      std::vector<std::vector<int>>& output,
      const std::vector<std::vector<int>>& graph,
      std::vector<int>& nodes,
      int node, const int n) {
    if (node == n) {
      output.push_back(nodes);
      output.back().push_back(node);
    } else {
      nodes.push_back(node);
      for (const int next : graph[node]) {
        backtrack(output, graph, nodes, next, n);
      }
      nodes.pop_back();
    }
  }
};
