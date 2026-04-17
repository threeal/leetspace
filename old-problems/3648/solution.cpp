class Solution {
 public:
  int minSensors(int n, int m, int k) {
    k = k * 2 + 1;
    return ((m + k - 1) / k) * ((n + k - 1) / k);
  }
};
