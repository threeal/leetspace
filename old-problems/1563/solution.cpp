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

    std::vector<std::vector<int>> caches(
        stoneValue.size(), std::vector<int>(stoneValue.size() + 1, -1));
    caches.front().resize(stoneValue.size(), 0);

    return find(caches.data(), sums.data(), stoneValue.size(), 0);
  }

 private:
  static int find(std::vector<int>* caches, int* sums, int n, int i) {
    auto& best = caches[n - 1][i];
    if (best < 0) {
      best = 0;
      for (int j = i + 1; j < i + n; ++j) {
        const int left{sums[j] - sums[i]};
        const int right{sums[i + n] - sums[j]};

        if (left <= right) {
          best = std::max(best, left + find(caches, sums, j - i, i));
        }

        if (right <= left) {
          best = std::max(best, right + find(caches, sums, i + n - j, j));
        }
      }
    }

    return best;
  }
};
