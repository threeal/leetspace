#include <algorithm>
#include <vector>

class Solution {
 public:
  int stoneGameV(std::vector<int>& stoneValue) {
    std::vector<int> sums(stoneValue.size() + 1);
    sums[0] = 0;
    for (std::size_t i{0}; i < stoneValue.size(); ++i) {
      sums[i + 1] = sums[i] + stoneValue[i];
    }

    std::vector<std::vector<int>> bests(stoneValue.size() + 1);
    bests[1].resize(stoneValue.size(), 0);

    for (std::size_t n{2}; n <= stoneValue.size(); ++n) {
      bests[n].resize(stoneValue.size() - n + 1, 0);
      for (std::size_t i{0}; i + n <= stoneValue.size(); ++i) {
        for (std::size_t j{i + 1}; j < i + n; ++j) {
          const int left{sums[j] - sums[i]};
          const int right{sums[i + n] - sums[j]};

          if (left <= right) {
            bests[n][i] = std::max(bests[n][i], left + bests[j - i][i]);
          }

          if (right <= left) {
            bests[n][i] = std::max(bests[n][i], right + bests[i + n - j][j]);
          }
        }
      }
    }

    return bests.back().back();
  }
};
