#include <vector>

extern "C" {
int largestRectangleArea(int* heights, int heightsSize);
}

int solution_c(std::vector<int> heights) {
  return largestRectangleArea(heights.data(), heights.size());
}
