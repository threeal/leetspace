class Solution {
 public:
  int smallestNumber(int n, int t) {
    while (true) {
      if (n >= 100) {
        if (((n / 100) * ((n / 10) % 10) * (n % 10)) % t == 0) return n;
      } else if (n >= 10) {
        if (((n / 10) * (n % 10)) % t == 0) return n;
      } else {
        if (n % t == 0) return n;
      }
      ++n;
    }
  }
};
