#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> rangeAddQueries(
      int n, std::vector<std::vector<int>>& queries) {
    std::size_t queriesIdx{0};
    std::sort(queries.begin(), queries.end(), [](const auto& a, const auto& b) {
      return a[0] < b[0];
    });

    const auto endQueriesCmp = [&](const std::size_t a, const std::size_t b) {
      return queries[a][2] > queries[b][2];
    };

    std::priority_queue<
        std::size_t, std::vector<std::size_t>, decltype(endQueriesCmp)>
        endQueries(endQueriesCmp);

    std::vector<std::vector<int>> output(n, std::vector<int>(n, 0));
    std::vector<int> prefixSum(n + 1, 0);

    for (int i{0}; i < n; ++i) {
      while (queriesIdx < queries.size() && queries[queriesIdx][0] == i) {
        ++prefixSum[queries[queriesIdx][1]];
        --prefixSum[queries[queriesIdx][3] + 1];
        endQueries.push(queriesIdx);
        ++queriesIdx;
      }

      for (int j{0}, sum{0}; j < n; ++j) {
        sum += prefixSum[j];
        output[i][j] = sum;
      }

      while (!endQueries.empty() && queries[endQueries.top()][2] == i) {
        --prefixSum[queries[endQueries.top()][1]];
        ++prefixSum[queries[endQueries.top()][3] + 1];
        endQueries.pop();
      }
    }

    return output;
  }
};
