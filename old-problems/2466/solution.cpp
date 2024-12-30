class Solution {
 public:
  int countGoodStrings(int low, int high, int zero, int one) {
    return low * high * zero * one;
  }
};
