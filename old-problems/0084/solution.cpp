#include <stack>
#include <vector>

class Solution {
 public:
  int largestRectangleArea(std::vector<int>& heights) {
    std::stack<std::size_t> indices{};
    std::vector<int> lefts(heights.size());
    for (std::size_t i{0}; i < heights.size(); ++i) {
      while (!indices.empty() && heights[indices.top()] >= heights[i]) {
        indices.pop();
      }

      lefts[i] = indices.empty() ? 0 : indices.top() + 1;
      indices.push(i);
    }

    while (!indices.empty()) indices.pop();

    std::vector<int> rights(heights.size());
    for (std::size_t i{heights.size()}; i > 0; --i) {
      while (!indices.empty() && heights[indices.top()] >= heights[i - 1]) {
        indices.pop();
      }

      rights[i - 1] = indices.empty() ? rights.size() - 1 : indices.top() - 1;
      indices.push(i - 1);
    }

    int largestArea{0};
    for (std::size_t i{0}; i < heights.size(); ++i) {
      const int area{heights[i] * (rights[i] - lefts[i] + 1)};
      if (area > largestArea) largestArea = area;
    }

    return largestArea;
  }
};
