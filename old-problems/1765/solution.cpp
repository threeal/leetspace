#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> highestPeak(
      std::vector<std::vector<int>>& isWater) {
    isWater.front().front() = isWater.front().front() == 0 ? 10000 : 0;
    for (std::size_t j{1}; j < isWater.front().size(); ++j) {
      isWater.front()[j] = isWater.front()[j] == 0
          ? isWater.front()[j - 1] + 1
          : 0;
    }

    for (std::size_t i{1}; i < isWater.size(); ++i) {
      isWater[i].front() = isWater[i].front() == 0
          ? isWater[i - 1].front() + 1
          : 0;

      for (std::size_t j{1}; j < isWater[i].size(); ++j) {
        isWater[i][j] = isWater[i][j] == 0
            ? std::min(isWater[i - 1][j] + 1, isWater[i][j - 1] + 1)
            : 0;
      }
    }

    for (std::size_t j{isWater.back().size()}; j > 1; --j) {
      isWater.back()[j - 2] =
          std::min(isWater.back()[j - 2], isWater.back()[j - 1] + 1);
    }

    for (std::size_t i{isWater.size()}; i > 1; --i) {
      isWater[i - 2].back() =
          std::min(isWater[i - 2].back(), isWater[i - 1].back() + 1);

      for (std::size_t j{isWater[i - 2].size()}; j > 1; --j) {
        isWater[i - 2][j - 2] = std::min(
            isWater[i - 2][j - 2],
            std::min(isWater[i - 1][j - 2] + 1, isWater[i - 2][j - 1] + 1));
      }
    }

    return isWater;
  }
};
