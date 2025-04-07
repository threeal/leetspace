#include <algorithm>
#include <numeric>
#include <stack>
#include <vector>

class Solution {
 public:
  int maximumScore(std::vector<int>& nums, int k) {
    const int maxNum{*std::max_element(nums.begin(), nums.end())};

    std::vector<int> primes(maxNum + 1, 0);
    for (int i{2}; i <= maxNum; ++i) {
      if (primes[i] == 0) {
        for (int j{i}; j <= maxNum; j += i) ++primes[j];
      }
    }

    std::vector<long long> counts(nums.size());
    std::stack<std::size_t> maxPrimes{};
    for (std::size_t i{0}; i < counts.size(); ++i) {
      while (!maxPrimes.empty() &&
             primes[nums[maxPrimes.top()]] < primes[nums[i]]) {
        maxPrimes.pop();
      }

      counts[i] = maxPrimes.empty() ? i + 1 : i - maxPrimes.top();
      maxPrimes.push(i);
    }

    while (!maxPrimes.empty()) maxPrimes.pop();
    for (std::size_t i{counts.size()}; i > 0;) {
      --i;

      while (!maxPrimes.empty() &&
             primes[nums[maxPrimes.top()]] <= primes[nums[i]]) {
        maxPrimes.pop();
      }

      counts[i] *= (maxPrimes.empty() ? counts.size() : maxPrimes.top()) - i;
      maxPrimes.push(i);
    }

    std::vector<std::size_t> indices(nums.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(indices.begin(), indices.end(), [&](const auto a, const auto b) {
      return nums[a] > nums[b];
    });

    long long score{1};
    for (const auto index : indices) {
      long long pow = k < counts[index] ? k : counts[index];
      k -= pow;

      long long num{nums[index]};
      while (pow > 0) {
        if (pow % 2 == 1) score = (score * num) % 1000000007;
        num = (num * num) % 1000000007;
        pow /= 2;
      }

      if (k == 0) break;
    }

    return score;
  }
};
