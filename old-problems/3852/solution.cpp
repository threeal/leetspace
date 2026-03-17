#include <vector>

class Solution {
 public:
  std::vector<int> minDistinctFreqPair(std::vector<int>& nums) {
    int freqs[101]{0};
    for (const int num : nums) ++freqs[num];

    for (int x{0}; x <= 100; ++x) {
      if (freqs[x] != 0) {
        for (int y{x + 1}; y <= 100; ++y) {
          if (freqs[y] != 0 && freqs[x] != freqs[y]) {
            return {x, y};
          }
        }
        break;
      }
    }

    return {-1, -1};
  }
};
