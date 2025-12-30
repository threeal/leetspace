#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  double trimMean(std::vector<int>& arr) {
    std::size_t twentieth{arr.size() / 20};
    std::partial_sort(arr.begin(), arr.begin() + twentieth, arr.end());

    std::partial_sort(
        arr.begin() + twentieth, arr.begin() + 2 * twentieth, arr.end(),
        std::greater<int>());

    const int sum{std::accumulate(arr.begin() + 2 * twentieth, arr.end(), 0)};
    return static_cast<double>(sum) / (arr.size() - 2 * twentieth);
  }
};
