#include <vector>

class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<int> res(n, 0);

    res[0] = 1;
    for (int i = 1; i < n; ++i) {
      res[i] = res[i - 1] * nums[i - 1];
    }

    int temp = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      res[i] *= temp;
      temp *= nums[i];
    }

    return res;
  }
};
