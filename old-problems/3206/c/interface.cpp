#include <vector>

extern "C" {
int numberOfAlternatingGroups(int* colors, int colorsSize);
}

int solution_c(std::vector<int> colors) {
  return numberOfAlternatingGroups(colors.data(), colors.size());
}
