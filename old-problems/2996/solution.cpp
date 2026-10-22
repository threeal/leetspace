#include <vector>

class Solution {
 public:
  int missingInteger(std::vector<int>& nums) {
    int sum{nums[0]};
    std::uint64_t flag{1ull << nums[0]};
    std::size_t i{1};

    while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
      sum += nums[i];
      flag |= 1ull << nums[i];
      ++i;
    }

    while (i < nums.size()) {
      flag |= 1ull << nums[i];
      ++i;
    }

    if (sum <= 50) {
      while ((flag & 1ull << sum) != 0) ++sum;
    }

    return sum;
  }
};
