#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
    int sum{std::accumulate(apple.begin(), apple.end(), 0)};
    std::sort(capacity.begin(), capacity.end(), std::greater<int>());

    std::size_t i{0};
    while (sum > 0) {
      sum -= capacity[i];
      ++i;
    }

    return i;
  }
};
