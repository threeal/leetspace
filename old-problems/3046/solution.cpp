#include <vector>

class Solution {
 public:
  bool isPossibleToSplit(std::vector<int>& nums) {
    char freqs[101] = {0};
    for (const auto num : nums) {
      if (++freqs[num] == 3) return false;
    }
    return true;
  }
};
