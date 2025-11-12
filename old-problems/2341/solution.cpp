#include <vector>

class Solution {
 public:
  std::vector<int> numberOfPairs(std::vector<int>& nums) {
    int freqs[101]{0};
    for (const int num : nums) ++freqs[num];

    int pairs{0}, leftovers{0};
    for (int num{0}; num <= 100; ++num) {
      pairs += freqs[num] / 2;
      leftovers += freqs[num] % 2;
    }

    return {pairs, leftovers};
  }
};
