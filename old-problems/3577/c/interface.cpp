#include <vector>

extern "C" {
int countPermutations(int* complexity, int complexitySize);
}

int solution_c(std::vector<int> complexity) {
  return countPermutations(complexity.data(), complexity.size());
}
