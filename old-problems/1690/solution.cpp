#include <vector>

class Solution {
 public:
  int stoneGameVII(std::vector<int>& stones) {
    for (std::size_t i = 1; i < stones.size(); ++i) {
      stones[i] += stones[i - 1];
    }

    std::vector<int> diffs = stones;
    std::vector<int> prevDiffs(stones.size(), 0);
    for (std::size_t i = 1; i < diffs.size(); ++i) {
      for (int j = diffs.size() - i - 1; j >= 0; --j) {
        diffs[j] = std::max(
            stones[j + i] - stones[j] - prevDiffs[j + 1],
            stones[j + i - 1] - (j > 0 ? stones[j - 1] : 0) - prevDiffs[j]);
      }
      std::swap(prevDiffs, diffs);
    }

    return prevDiffs[0];
  }
};
