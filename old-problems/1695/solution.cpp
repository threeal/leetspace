#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maximumUniqueSubarray(std::vector<int>& nums) {
    int maxSum{0}, sum{0};
    std::unordered_map<int, bool> uniques{};
    for (std::size_t l{0}, r{0}; r < nums.size(); ++r) {
      while (uniques[nums[r]]) {
        uniques[nums[l]] = false;
        sum -= nums[l];
        ++l;
      }
      uniques[nums[r]] = true;
      sum += nums[r];
      if (sum > maxSum) maxSum = sum;
    }
    return maxSum;
  }
};
