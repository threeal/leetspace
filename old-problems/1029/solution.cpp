#include <algorithm>
#include <vector>

class Solution {
 public:
  int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
    const std::size_t half{costs.size() / 2};
    std::partial_sort(
        costs.begin(), costs.begin() + half, costs.end(),
        [](const auto& a, const auto& b) {
          return a[0] - a[1] < b[0] - b[1];
        });

    int sum{0};
    for (std::size_t i{0}; i < half; ++i) sum += costs[i][0];
    for (std::size_t i{half}; i < costs.size(); ++i) sum += costs[i][1];
    return sum;
  }
};
