#include <vector>

class Solution {
 public:
  int minSumOfLengths(std::vector<int>& arr, int target) {
    std::size_t minLength{arr.size() + 1}, minSumLength{arr.size() + 1};
    std::vector<std::size_t> minLengths(arr.size());

    int sum{0};
    for (std::size_t l{0}, r{0}; r < arr.size(); ++r) {
      minLengths[r] = minLength;

      sum += arr[r];
      while (sum > target) {
        sum -= arr[l];
        ++l;
      }

      if (sum == target) {
        const std::size_t length{r + 1 - l};
        if (minLengths[l] + length < minSumLength) {
          minSumLength = minLengths[l] + length;
        }
        if (length < minLength) minLength = length;
      }
    }

    return minSumLength <= arr.size() ? minSumLength : -1;
  }
};
