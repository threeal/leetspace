#include <vector>

extern "C" {
int distributeCandies(int* candyType, int candyTypeSize);
}

int solution_c(std::vector<int> candyType) {
  return distributeCandies(candyType.data(), candyType.size());
}
