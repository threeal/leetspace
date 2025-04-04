#include <vector>

extern "C" {
long long putMarbles(int* weights, int weightsSize, int k);
}

long long solution_c(std::vector<int> weights, int k) {
  return putMarbles(weights.data(), weights.size(), k);
}
