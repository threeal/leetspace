#include <vector>

extern "C" {
int maxDistance(int* colors, int colorsSize);
}

int solution_c(std::vector<int> colors) {
  return maxDistance(colors.data(), colors.size());
}
