#include <list>
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<int> shortestDistanceAfterQueries(
      int n, std::vector<std::vector<int>>& queries) {
    std::vector<int> nodeDistance(n, 0);
    std::vector<std::list<int>> nodePrevious(n);

    nodeDistance[0] = n - 1;
    for (int i{1}; i < n; ++i) {
      nodeDistance[i] = n - i - 1;
      nodePrevious[i].push_back(i - 1);
    }

    std::vector<int> output{};
    output.reserve(queries.size());

    for (const auto& query : queries) {
      nodePrevious[query[1]].push_back(query[0]);
      if (nodeDistance[query[0]] > 1 + nodeDistance[query[1]]) {
        nodeDistance[query[0]] = 1 + nodeDistance[query[1]];

        std::queue<int> q{};
        q.push(query[0]);

        while (!q.empty()) {
          const auto node = q.front();
          q.pop();

          for (const auto prev : nodePrevious[node]) {
            if (nodeDistance[prev] > 1 + nodeDistance[node]) {
              nodeDistance[prev] = 1 + nodeDistance[node];
              q.push(prev);
            }
          }
        }
      }

      output.push_back(nodeDistance.front());
    }

    return output;
  }
};
