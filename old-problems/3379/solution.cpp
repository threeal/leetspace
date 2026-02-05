#include <vector>

class Solution {
 public:
  std::vector<int> constructTransformedArray(std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<int> output(n);
    for (int i{0}; i < n; ++i) {
      output[i] = nums[(n + (i + nums[i]) % n) % n];
    }
    return output;
  }
};
