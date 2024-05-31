#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> singleNumber(std::vector<int>& nums) {
    const int sum{std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor())};

    int mask{1};
    while ((sum & mask) == 0) {
      mask = mask << 1;
    }

    int a{0};
    int b{0};
    for (const int num : nums) {
      if ((num & mask) == 0) {
        b ^= num;
      } else {
        a ^= num;
      }
    }

    return {a, b};
  }
};
