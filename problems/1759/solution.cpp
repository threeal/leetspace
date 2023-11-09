const long long mod = 1'000'000'007;

class Solution {
 public:
  int countHomogenous(string s) {
    long long total = 0;

    char prev = 0;
    long long n = 0;
    for (const auto c : s) {
      if (prev == c) {
        ++n;
      } else {
        total = (total + sumHomogenous(n)) % mod;
        prev = c;
        n = 1;
      }
    }

    return (total + sumHomogenous(n)) % mod;
  }

  long long sumHomogenous(long long n) {
    if (n <= 1) return n;
    return ((n + 1) * n) / 2;
  }
};
