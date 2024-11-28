class Solution {
 public:
  int reverse(int x) {
    if (x == -2147483648) return 0;

    int out{0};

    bool isNeg{false};
    if (x < 0) {
      isNeg = true;
      x = -x;
    }

    while (x > 0) {
      if (out >= 214748364) {
        if (out > 214748364) return 0;
        if (x % 10 > 7) return 0;
      }

      out = out * 10 + x % 10;
      x /= 10;
    }

    return isNeg ? -out : out;
  }
};
