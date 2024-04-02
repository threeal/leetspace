#include <vector>

class Solution {
 public:
  int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
    std::vector<int> cache(arr.size(), -1);
    return recursive(arr, k, cache, 1, arr[0], 1);
  }

  int recursive(const std::vector<int>& arr, int k, std::vector<int>& cache, std::size_t i, int maxVal, int len) {
    if (i >= arr.size()) {
      return maxVal * len;
    }

    if (len >= k) {
      return maxVal * len + recursive(arr, k, cache, i + 1, arr[i], 1);
    }

    if (len == 1 && cache[i] > 0) {
      return cache[i];
    }

    const auto res = std::max(
        recursive(arr, k, cache, i + 1, std::max(maxVal, arr[i]), len + 1),
        maxVal * len + recursive(arr, k, cache, i + 1, arr[i], 1));

    if (len == 1) {
      cache[i] = res;
    }

    return res;
  }
};
