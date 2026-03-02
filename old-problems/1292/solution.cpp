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

    for (std::size_t i{1}; i < mat.size(); ++i) {
      for (std::size_t j{0}; j < mat[i].size(); ++j) {
        mat[i][j] += mat[i - 1][j];
      }
    }

    std::size_t low{0}, high{std::min(mat.size(), mat[0].size())};
    while (low < high) {
      const std::size_t mid{high - (high - low) / 2};
      if (mid == 0 || checkSideLength(mat, threshold, mid)) {
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
    if (mat[n - 1][n - 1] <= threshold) return true;
    for (std::size_t i{n}; i < mat[0].size(); ++i) {
      if (mat[n - 1][i] - mat[n - 1][i - n] <= threshold) return true;
    }

    for (std::size_t i{n}; i < mat.size(); ++i) {
      if (mat[i][n - 1] - mat[i - n][n - 1] <= threshold) return true;
      for (std::size_t j{n}; j < mat[i].size(); ++j) {
        const int sum{
            mat[i][j] - mat[i - n][j] - mat[i][j - n] + mat[i - n][j - n]};
        if (sum <= threshold) return true;
      }
    }

    return false;
  }
};
