#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    for (std::size_t i{1}; i < triangle.size(); ++i) {
      triangle[i].front() += triangle[i - 1].front();
      for (std::size_t j{triangle[i].size() - 2}; j > 0; --j) {
        triangle[i][j] += std::min(triangle[i - 1][j - 1], triangle[i - 1][j]);
      }
      triangle[i].back() += triangle[i - 1].back();
    }
    return *std::min_element(triangle.back().begin(), triangle.back().end());
  }
};
