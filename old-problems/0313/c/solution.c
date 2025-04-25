#include <limits.h>
#include <stdlib.h>

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
  long long* nums = malloc(n * sizeof(long long));
  nums[0] = 1;

  int* primeIndices = malloc(primesSize * sizeof(int));
  for (int i = 0; i < primesSize; ++i) primeIndices[i] = 0;

  for (int i = 1; i < n; ++i) {
    long long min = LLONG_MAX;
    for (int i = 0; i < primesSize; ++i) {
      const long long num = nums[primeIndices[i]] * primes[i];
      if (num < min) min = num;
    }

    for (int i = 0; i < primesSize; ++i) {
      const long long num = nums[primeIndices[i]] * primes[i];
      if (num == min) ++primeIndices[i];
    }

    nums[i] = min;
  }

  return nums[n - 1];
}
