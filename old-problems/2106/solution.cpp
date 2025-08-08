#include <vector>

class Solution {
 public:
  int maxTotalFruits(
      std::vector<std::vector<int>>& fruits, int startPos, int k) {
    if (fruits.front()[0] >= startPos) {
      const int maxPos{startPos + k};
      int total{0};
      for (const auto& fruit : fruits) {
        if (fruit[0] > maxPos) break;
        total += fruit[1];
      }
      return total;
    }

    if (fruits.back()[0] <= startPos) {
      const int minPos{startPos - k};
      int total{0};
      std::size_t i{fruits.size()};
      while (i > 0) {
        --i;
        if (fruits[i][0] < minPos) break;
        total += fruits[i][1];
      }
      return total;
    }

    std::size_t low{0}, high{fruits.size() - 1};
    while (low < high) {
      const std::size_t mid{low + (high - low) / 2};
      if (fruits[mid][0] < startPos) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    int total{0};
    for (std::size_t i{0}; i < low; ++i) {
      total += fruits[i][1];
    }

    int maxTotal{0};
    for (std::size_t l{0}, r{low}; r < fruits.size(); ++r) {
      total += fruits[r][1];
      while (total != 0 &&
            fruits[r][0] - startPos + fruits[r][0] - fruits[l][0] > k) {
        total -= fruits[l][1];
        ++l;
      }
      if (total == 0) break;
      if (total > maxTotal) maxTotal = total;
    }

    return maxTotal;
  }
};
