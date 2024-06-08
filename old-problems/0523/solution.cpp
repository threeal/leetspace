#include <vector>

class Solution {
 public:
  bool checkSubarraySum(std::vector<int>& nums, int k) {
    int sum{nums[nums.size() - 1]};
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] == 0 && nums[i] == nums[i + 1]) return true;

      sum += nums[i];
      if (sum % k == 0) return true;

      int tempSum{sum};
      for (int j = nums.size() - 1; j > i + 1 && tempSum > k; --j) {
        tempSum -= nums[j];
        if (tempSum % k == 0) return true;
      }
    }
    return false;
  }
};
