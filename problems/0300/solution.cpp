#include <functional>
#include <limits>
#include <vector>

class Solution {
 public:
  int lengthOfLIS(std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<int> cache(n, -1);

    const std::function<int(int)> fn = [&](int start) {
      if (start >= n) return 0;
      if (cache[start] >= 0) {
        return cache[start];
      }

      int length = 0;
      const int num = start > 0 ? nums[start - 1] : std::numeric_limits<int>::min();
      for (int i = start; i < n; ++i) {
        if (num >= nums[i]) continue;
        length = std::max(length, 1 + fn(i + 1));
      }
      return cache[start] = length;
    };

    return fn(0);
  }
};
