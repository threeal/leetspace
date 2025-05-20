#include <vector>

class Solution {
 public:
  bool isZeroArray(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    const int n = nums.size();
    for (int i{n - 1}; i > 0; --i) {
      nums[i] -= nums[i - 1];
    }

    for (const std::vector<int>& query : queries) {
      --nums[query[0]];
      if (query[1] + 1 < n) ++nums[query[1] + 1];
    }

    int num{0};
    for (int i{0}; i < n; ++i) {
      num += nums[i];
      if (num > 0) return false;
    }

    return true;
  }
};
