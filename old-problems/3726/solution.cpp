class Solution {
 public:
  long long removeZeros(long long n) {
    long long res{0}, exp{1};
    while (n != 0) {
      if (n % 10 != 0) {
        res += n % 10 * exp;
        exp *= 10;
      }
      n /= 10;
    }
    return res;
  }
};
