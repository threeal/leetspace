#include <functional>
#include <vector>

class Solution {
 public:
  int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
    const std::function<int(std::size_t, int, int)> fn = [&](std::size_t i, int maxVal, int len) -> int {
      if (i >= arr.size()) {
        return maxVal * len;
      }

      if (len >= k) {
        return maxVal * len + fn(i + 1, arr[i], 1);
      }

      return std::max(
          fn(i + 1, std::max(maxVal, arr[i]), len + 1),
          maxVal * len + fn(i + 1, arr[i], 1));
    };

    return fn(1, arr[0], 1);
  }
};
