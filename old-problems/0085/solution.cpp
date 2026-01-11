#include <stack>
#include <vector>

class Solution {
 public:
  int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    int maxArea{0};
    std::vector<int> heights(matrix[0].size(), 0);
    for (const auto& row : matrix) {
      if (row[0] == '0') {
        heights[0] = 0;
      } else {
        ++heights[0];
      }

      std::stack<std::size_t> indices{};
      indices.push(0);

      for (std::size_t i{1}; i < row.size(); ++i) {
        if (row[i] == '0') {
          heights[i] = 0;
        } else {
          ++heights[i];
        }

        while (!indices.empty() && heights[i] < heights[indices.top()]) {
          const std::size_t idx{indices.top()};
          indices.pop();

          const int width = indices.empty() ? i : i - indices.top() - 1;
          const int area{heights[idx] * width};
          if (area > maxArea) maxArea = area;
        }

        indices.push(i);
      }

      while (!indices.empty()) {
        const std::size_t idx{indices.top()};
        indices.pop();

        const int width =
            indices.empty() ? row.size() : row.size() - indices.top() - 1;

        const int area{heights[idx] * width};
        if (area > maxArea) maxArea = area;
      }
    }

    return maxArea;
  }
};
