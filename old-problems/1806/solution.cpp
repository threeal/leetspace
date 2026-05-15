class Solution {
 public:
  int reinitializePermutation(int n) {
    int ops{1};
    int x{n / 2};
    while (x != 1) {
      if (x % 2 == 0) {
        x /= 2;
      } else {
        x = (n + x) / 2;
      }
      ++ops;
    }
    return ops;
  }
};
