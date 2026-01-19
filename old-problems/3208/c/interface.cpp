#include <vector>

extern "C" {
int numberOfAlternatingGroups(int* colors, int colorsSize, int k);
}

int solution_c(std::vector<int> colors, int k) {
  return numberOfAlternatingGroups(colors.data(), colors.size(), k);
}
