#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> leftmostBuildingQueries(
      std::vector<int>& heights, std::vector<std::vector<int>>& queries) {
    for (auto& query : queries) {
      if (query[0] > query[1]) std::swap(query[0], query[1]);
    }

    std::vector<std::size_t> queryIndices(queries.size());
    std::iota(queryIndices.begin(), queryIndices.end(), 0);

    std::sort(
        queryIndices.begin(), queryIndices.end(),
        [&queries](std::size_t a, std::size_t b) {
          return queries[a][1] > queries[b][1];
        });

    std::vector<std::size_t> nexts{};
    std::size_t nextsI{heights.size() - 1};

    std::vector<int> output(queries.size());
    for (std::size_t i : queryIndices) {
      const std::size_t alice = queries[i][0];
      const std::size_t bob = queries[i][1];

      if (alice == bob || heights[alice] < heights[bob]) {
        output[i] = bob;
        continue;
      }

      while (nextsI > bob) {
        while (!nexts.empty() && heights[nexts.back()] <= heights[nextsI]) {
          nexts.pop_back();
        }
        nexts.push_back(nextsI--);
      }

      while (!nexts.empty() && heights[nexts.back()] <= heights[bob]) {
        nexts.pop_back();
      }

      const auto it = std::lower_bound(
          nexts.rbegin(), nexts.rend(), heights[alice],
          [&heights](std::size_t j, int height) {
            return heights[j] <= height;
          });

      output[i] = it != nexts.rend() ? *it : -1;
    }

    return output;
  }
};
