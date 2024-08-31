#include <list>
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  double maxProbability(
      int n, std::vector<std::vector<int>>& edges,
      std::vector<double>& succProb, int start, int end) {
    std::vector<std::list<std::pair<double, int>>> neighbors(n);
    for (int i = edges.size() - 1; i >= 0; --i) {
      neighbors[edges[i][0]].push_back({succProb[i], edges[i][1]});
      neighbors[edges[i][1]].push_back({succProb[i], edges[i][0]});
    }

    std::vector<double> maxProb(n, 0.0);
    maxProb[start] = 1.0;

    std::queue<int> queue{};
    queue.push(start);

    while (!queue.empty()) {
      const auto node = queue.front();
      queue.pop();

      for (const auto& neighbor : neighbors[node]) {
        const auto newProb = maxProb[node] * neighbor.first;
        if (newProb > maxProb[neighbor.second]) {
          maxProb[neighbor.second] = newProb;
          queue.push(neighbor.second);
        }
      }
    }

    return maxProb[end];
  }
};
