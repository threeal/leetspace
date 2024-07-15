#include <vector>

class Solution {
 public:
  int countPrimes(int n) {
    if (n < 2) return 0;
    int count{0};

    std::vector<bool> nums(n, false);
    for (int i{2}; i < n; ++i) {
      if (!nums[i]) {
        ++count;
        for (int j{i + i}; j < n; j += i) nums[j] = true;
      }
    }

    return count;
  }
};
