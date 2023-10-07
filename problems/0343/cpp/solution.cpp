class Solution {
 public:
  int integerBreak(int n) {
    int res = 0;
    for (int i = 2; i <= n; ++i) {
      const int div = n / i;
      const int mod = n % i;

      int new_res = div;
      for (int j = 0; j < i - 1; ++j) {
        new_res *= div;
      }

      if (res > 0) {
        new_res /= div;
        new_res *= max(div + mod, div * mod);
      }

      if (new_res > res) {
        res = new_res;
      }
    }

    return res;
  }
};
