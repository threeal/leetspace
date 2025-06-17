#include <array>

static constexpr long long qpow(long long x, int n) {
  long long res{1};
  while (n != 0) {
    if (n % 2 != 0) res = res * x % 1000000007;
    x = x * x % 1000000007;
    n /= 2;
  }
  return res;
}

static constexpr std::array<long long, 100000> calcFact() {
  std::array<long long, 100000> fact{};
  fact[0] = 1;
  for (long long i{1}; i < 100000; ++i) {
    fact[i] = fact[i - 1] * i % 1000000007;
  }
  return fact;
}

static constexpr std::array<long long, 100000> calcInvFact(
    const std::array<long long, 100000>& fact) {
  std::array<long long, 100000> invFact{};
  invFact[99999] = qpow(fact[99999], 1000000005);
  for (long long i{99999}; i > 0; --i) {
    invFact[i - 1] = invFact[i] * i % 1000000007;
  }
  return invFact;
}

class Solution {
 public:
  int countGoodArrays(int n, int m, int k) {
    static constexpr std::array<long long, 100000> fact{calcFact()};
    static constexpr std::array<long long, 100000> invFact{calcInvFact(fact)};
    const long long comb{
        fact[n - 1] * invFact[k] % 1000000007 * invFact[n - 1 - k] % 1000000007};
    return m * comb % 1000000007 * qpow(m - 1, n - 1 - k) % 1000000007;
  }
};
