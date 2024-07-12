#include <cstdint>

class Solution {
 public:
  int numPrimeArrangements(int n) {
    std::int8_t primes[26]{
        0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
        67, 71, 73, 79, 83, 89, 97};

    for (std::int8_t i = 25; i > 0; --i) {
      if (n >= primes[i]) {
        long long count{1};
        for (std::int8_t j{i}; j > 0; --j) {
          count = (count * j) % 1000000007;
        }
        for (std::int8_t j = n - i; j > 0; --j) {
          count = (count * j) % 1000000007;
        }
        return count;
      }
    }

    return 1;
  }
};
