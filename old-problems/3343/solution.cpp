#include <array>
#include <string>
#include <vector>

static constexpr int mod{1000000007};

static constexpr std::array<long long, 41> calcFactorial() {
  std::array<long long, 41> fact{};
  fact.fill(1);

  for (int i{1}; i < 41; ++i) {
    fact[i] = fact[i - 1] * i % mod;
  }
  return fact;
}

static constexpr std::array<long long, 81> calcInvFactorial() {
  std::array<long long, 81> inv{};
  inv.fill(1);

  for (int i{2}; i < 81; ++i) {
    inv[i] = mod - (mod / i) * inv[mod % i] % mod;
  }

  std::array<long long, 81> invFact{};
  invFact.fill(1);

  for (int i{1}; i < 81; ++i) {
    invFact[i] = invFact[i - 1] * inv[i] % mod;
  }

  return invFact;
}

class Solution {
 public:
  int countBalancedPermutations(std::string num) {
    static constexpr std::array<long long, 41> fact{calcFactorial()};
    static constexpr std::array<long long, 81> invFact{calcInvFactorial()};

    int sum{0};
    for (const char c : num) sum += c - '0';
    if (sum % 2 != 0) return 0;
    sum /= 2;

    const std::size_t n{num.size() / 2};
    std::vector<std::vector<int>> dp(sum + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;

    std::array<int, 10> digits{};
    digits.fill(0);

    for (const char c : num) {
      const int d{c - '0'};
      ++digits[d];

      for (int i{sum}; i >= d; --i) {
        for (std::size_t j{n}; j > 0; --j) {
          dp[i][j] = (dp[i][j] + dp[i - d][j - 1]) % mod;
        }
      }
    }

    long long count{dp[sum][n] * fact[n] % mod * fact[num.size() - n] % mod};
    for (const int i : digits) {
      count = count * invFact[i] % mod;
    }

    return count;
  }
};
