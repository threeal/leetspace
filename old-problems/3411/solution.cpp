#include <numeric>
#include <vector>

class Solution {
 public:
  int maxLength(std::vector<int>& nums) {
    std::size_t l{0}, max{2};
    int product{1};
    for (std::size_t r{0}; r < nums.size(); ++r) {
      while (std::gcd(product, nums[r]) > 1) product /= nums[l++];
      product *= nums[r];
      if (r - l + 1 > max) max = r - l + 1;
    }
    return max;
  }
};
