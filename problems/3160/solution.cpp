#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> queryResults(
      int limit, std::vector<std::vector<int>>& queries) {
    (void)limit;

    std::unordered_map<int, int> balls{};
    std::unordered_map<int, int> colors{};
    int colorsCount{0};

    std::vector<int> results(queries.size());
    for (std::size_t i{0}; i < queries.size(); ++i) {
      if (balls[queries[i][0]] > 0) {
        if (--colors[balls[queries[i][0]]] == 0) --colorsCount;
      }

      balls[queries[i][0]] = queries[i][1];
      if (++colors[queries[i][1]] == 1) ++colorsCount;

      results[i] = colorsCount;
    }

    return results;
  }
};
