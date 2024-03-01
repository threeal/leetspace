#include <vector>

#define MOD 1000000007

class Solution {
 public:
  int sumSubarrayMins(std::vector<int>& arr) {
    const int n = arr.size();
    std::vector<std::vector<int>> cache(n);

    int sum = 0;

    cache[0].resize(n);
    for (int i = 0; i < n; ++i) {
      cache[0][i] = arr[i];
      sum = (sum + cache[0][i]) % MOD;
    }

    for (int i = 1; i < n; ++i) {
      cache[i].resize(n - i);
      for (int j = 0; j < n - i; ++j) {
        cache[i][j] = std::min(cache[i - 1][j], arr[j + i]);
        sum = (sum + cache[i][j]) % MOD;
      }
    }

    return sum;
  }
};
