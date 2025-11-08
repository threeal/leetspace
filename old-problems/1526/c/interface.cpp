#include <vector>

extern "C" {
int minNumberOperations(int* target, int targetSize);
}

int solution_c(std::vector<int> target) {
  return minNumberOperations(target.data(), target.size());
}
