#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
    int out{-1};
    for (auto num : nums) {
      while (out >= 0) {
        const int gcd{std::gcd(nums[out], num)};
        if (gcd == 1) break;
        num /= gcd;
        num *= nums[out];
        --out;
      }
      nums[++out] = num;
    }
    nums.resize(out + 1);
    return nums;
  }
};
