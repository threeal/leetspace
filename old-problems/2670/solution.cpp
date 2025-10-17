#include <vector>

class Solution {
 public:
  std::vector<int> distinctDifferenceArray(std::vector<int>& nums) {
    int sFreqs[51]{0}, sCount{0};
    for (const int num : nums) {
      if (++sFreqs[num] == 1) ++sCount;
    }

    int pFreqs[51]{0}, pCount{0};
    for (int& num : nums) {
      if (++pFreqs[num] == 1) ++pCount;
      if (--sFreqs[num] == 0) --sCount;
      num = pCount - sCount;
    }

    return nums;
  }
};
