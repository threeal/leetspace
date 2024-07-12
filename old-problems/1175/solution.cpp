#include <vector>

class Solution {
 public:
  int numPrimeArrangements(int n) {
    const std::vector<int> primes{
        0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
        67, 71, 73, 79, 83, 89, 97};

    for (int i = primes.size() - 1; i >= 0; --i) {
      if (n >= primes[i]) {
        long long count{1};
        for (int j = i; j > 0; --j) {
          count = (count * j) % 1000000007;
        }
        for (int j = n - i; j > 0; --j) {
          count = (count * j) % 1000000007;
        }
        return count;
      }
    }

    return 0;
  }
};
