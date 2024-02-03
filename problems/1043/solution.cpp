#include <functional>
#include <vector>

class Solution {
 public:
  int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
    std::vector<int> cache(arr.size(), -1);

    const std::function<int(std::size_t, int, int)> fn = [&](std::size_t i, int maxVal, int len) -> int {
      if (i >= arr.size()) {
        return maxVal * len;
      }

      if (len >= k) {
        return maxVal * len + fn(i + 1, arr[i], 1);
      }

      if (len == 1 && cache[i] > 0) {
        return cache[i];
      }

      const auto res = std::max(
          fn(i + 1, std::max(maxVal, arr[i]), len + 1),
          maxVal * len + fn(i + 1, arr[i], 1));

      if (len == 1) {
        cache[i] = res;
      }

      return res;
    };

    return fn(1, arr[0], 1);
  }
};
