#include <utility>
#include <vector>

class Solution {
 public:
  bool stoneGame(std::vector<int>& piles) {
    std::vector<int> prevDiffs = piles, diffs;
    for (std::size_t i = 1; i < diffs.size(); ++i) {
      for (int j = diffs.size() - i - 1; j >= 0; --j) {
        diffs[j] = std::max(
            piles[j] - prevDiffs[j + i], piles[j + i] - prevDiffs[j]);
      }
      std::swap(prevDiffs, diffs);
    }
    return prevDiffs[0] > 0;
  }
};
