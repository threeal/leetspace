class Solution {
 public:
  bool hasAlternatingBits(int n) {
    for (int i{1}; i < 32 && (1 << i) <= n; ++i) {
      if (((n >> i) & 1) == ((n >> (i - 1)) & 1)) return false;
    }
    return true;
  }
};
