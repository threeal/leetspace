#include <bit>

class Solution {
 public:
  int concatenatedBinary(int n) {
    long long ans{0};
    for (int i{1}; i <= n; ++i) {
      ans = ((ans << (32 - std::countl_zero<unsigned int>(i))) | i) % 1000000007;
    }
    return ans;
  }
};
