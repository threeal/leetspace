class Solution {
 public:
  bool isPowerOfFour(int n) {
    if (n < 4) return n == 1;

    while (n > 4) {
      if (n % 4 > 0) return false;
      n /= 4;
    }

    return true;
  }
};
