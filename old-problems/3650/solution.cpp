#include <queue>
#include <unordered_map>
#include <vector>

struct Next {
  int node;
  int cost;
};

struct Step {
  int node;
  int cost;
};

struct CompareStep {
  bool operator()(const Step& a, const Step& b) const {
    return a.cost > b.cost;
  }
};

class Solution {
 public:
  int minCost(int n, std::vector<std::vector<int>>& edges) {
    std::unordered_map<int, std::vector<Next>> nexts{};
    for (const auto& edge : edges) {
      nexts[edge[0]].push_back({.node = edge[1], .cost = edge[2]});
      nexts[edge[1]].push_back({.node = edge[0], .cost = edge[2] * 2});
    }

    std::priority_queue<Step, std::vector<Step>, CompareStep> steps{};
    steps.push({.node = 0, .cost = 0});

    std::vector<bool> isVisited(n, false);

    while (!steps.empty()) {
      const auto step = steps.top();
      steps.pop();

      if (step.node == n - 1) return step.cost;

      if (!isVisited[step.node]) {
        isVisited[step.node] = true;
        for (const auto& next : nexts[step.node]) {
          if (!isVisited[next.node]) {
            steps.push({.node = next.node, .cost = step.cost + next.cost});
          }
        }
      }
    }

    return -1;
  }
};
