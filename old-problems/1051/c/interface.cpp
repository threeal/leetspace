#include <vector>

extern "C" {
int heightChecker(int* heights, int heightsSize);
}

int solution_c(std::vector<int> heights) {
  return heightChecker(heights.data(), heights.size());
}
