class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    if (dividend == -2147483648 && divisor == -1) {
      return 2147483647;
    }

    bool isPositive{(dividend >= 0) == (divisor >= 0)};

    unsigned int a = dividend < 0
        ? (dividend == -2147483648 ? 2147483648u : -dividend)
        : dividend;

    unsigned int b = divisor < 0
        ? (divisor == -2147483648 ? 2147483648u : -divisor)
        : divisor;

    unsigned int c{0};
    while (a >= b) {
      int e{0};
      while (a > (b << (e + 1))) ++e;
      c += 1 << e;
      a -= b << e;
    }

    return isPositive ? c : -c;
  }
};
