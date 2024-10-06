#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> countServers(
      int n, std::vector<std::vector<int>>& logs, int x,
      std::vector<int>& queries) {
    std::sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
      return a[1] < b[1];
    });

    std::vector<int> queryIdxs(queries.size());
    std::iota(queryIdxs.begin(), queryIdxs.end(), 0);
    std::sort(
        queryIdxs.begin(), queryIdxs.end(),
        [&queries](const auto a, const auto b) {
          return queries[a] < queries[b];
        });

    int currentMissing{n};
    std::vector<int> currentRequests(n, 0);
    auto startLog = logs.begin();
    auto endLog = logs.begin();

    std::vector<int> missings(queries.size());
    for (std::size_t i{0}; i < queryIdxs.size(); ++i) {
      const int end{queries[queryIdxs[i]]};
      while (startLog != logs.end() && (*startLog)[1] <= end) {
        const int id{(*startLog)[0] - 1};
        if (currentRequests[id] == 0) --currentMissing;
        ++currentRequests[id];
        ++startLog;
      }

      const int start{queries[queryIdxs[i]] - x};
      while (endLog != logs.end() && (*endLog)[1] < start) {
        const int id{(*endLog)[0] - 1};
        if (currentRequests[id] == 1) ++currentMissing;
        --currentRequests[id];
        ++endLog;
      }

      missings[queryIdxs[i]] = currentMissing;
    }

    return missings;
  }
};
