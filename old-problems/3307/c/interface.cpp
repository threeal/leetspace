#include <vector>

extern "C" {
char kthCharacter(long long k, int* operations, int operationsSize);
}

char solution_c(long long k, std::vector<int> operations) {
  return kthCharacter(k, operations.data(), operations.size());
}
