#include <vector>

class Solution {
 public:
  int sumOfPrimesInRange(int n) {
    int rn{0};
    for (int nn{n}; nn != 0; nn /= 10) {
      rn = rn * 10 + nn % 10;
    }

    const int min{rn < n ? rn : n};
    const int max{rn > n ? rn : n};

    int sum{0};
    std::vector<bool> sieve(max + 1, false);
    for (int i{2}; i <= max; ++i) {
      if (sieve[i]) continue;
      if (i >= min) sum += i;
      for (int j{i}; j <= max; j += i) {
        sieve[j] = true;
      }
    }

    return sum;
  }
};
