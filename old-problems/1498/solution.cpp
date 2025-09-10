#include <algorithm>
#include <array>
#include <vector>

constexpr std::array<int, 100001> generatePow2() {
  std::array<int, 100001> pow2{};
  pow2[0] = 1;
  for (std::size_t i{1}; i < 100001; ++i) {
    pow2[i] = (pow2[i - 1] * 2) % 1000000007;
  }
  return pow2;
}

class Solution {
 public:
  int numSubseq(std::vector<int>& nums, int target) {
    int total{0};

    static constexpr std::array<int, 100001> pow2{generatePow2()};
    std::sort(nums.begin(), nums.end());

    std::size_t l{0}, r{nums.size()};
    while (l < r) {
      if (nums[l] + nums[r - 1] <= target) {
        total = (total + pow2[r - 1 - l]) % 1000000007;
        ++l;
      } else {
        --r;
      }
    }

    return total;
  }
};
