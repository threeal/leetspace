class Solution {
 public:
  int countPrimeSetBits(int left, int right) {
    return right + 1 - left;
  }
};
