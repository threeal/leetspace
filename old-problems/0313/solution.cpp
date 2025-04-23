#include <limits>
#include <vector>

class Solution {
 public:
  int nthSuperUglyNumber(int n, std::vector<int>& primes) {
    std::vector<long long> nums(n);
    nums[0] = 1;

    std::vector<int> primeIndices(primes.size(), 0);
    for (int i{1}; i < n; ++i) {
      long long min{std::numeric_limits<long long>::max()};
      for (std::size_t i{0}; i < primes.size(); ++i) {
        const long long num{nums[primeIndices[i]] * primes[i]};
        if (num < min) min = num;
      }

      for (std::size_t i{0}; i < primes.size(); ++i) {
        const long long num{nums[primeIndices[i]] * primes[i]};
        if (num == min) ++primeIndices[i];
      }

      nums[i] = min;
    }

    return nums.back();
  }
};
