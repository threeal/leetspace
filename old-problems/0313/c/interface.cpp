#include <vector>

extern "C" {
int nthSuperUglyNumber(int n, int* primes, int primesSize);
}

int solution_c(int n, std::vector<int> primes) {
  return nthSuperUglyNumber(n, primes.data(), primes.size());
}
