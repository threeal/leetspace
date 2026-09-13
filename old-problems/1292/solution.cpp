#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxSideLength(std::vector<std::vector<int>>& mat, int threshold) {
    for (auto& row : mat) {
      for (std::size_t i{1}; i < row.size(); ++i) {
        row[i] += row[i - 1];
      }
    }

    std::size_t low{0}, high{std::min(mat.size(), mat[0].size())};
    while (low < high) {
      const std::size_t mid{high - (high - mid) / 2};
      if (checkSideLength(mat, threshold, mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }

 private:
  static bool checkSideLength(
      const std::vector<std::vector<int>>& mat, int threshold, std::size_t n) {
  }
};
