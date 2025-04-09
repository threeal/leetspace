#include <utility>

class Solution {
 public:
  int checkRecord(int n) {
    int prev[6], curr[6]{1, 1, 0, 1, 0, 0};

    while (--n > 0) {
      std::swap(prev, curr);

      curr[0] = sum(sum(prev[0], prev[1]), prev[2]);
      curr[1] = prev[0];
      curr[2] = prev[1];
      curr[3] = sum(sum(sum(sum(sum(prev[0], prev[1]), prev[2]), prev[3]), prev[4]), prev[5]);
      curr[4] = prev[3];
      curr[5] = prev[4];
    }

    return sum(sum(sum(sum(sum(curr[0], curr[1]), curr[2]), curr[3]), curr[4]), curr[5]);
  }

 private:
  static int sum(int a, int b) {
    return (a + b) % 1000000007;
  }
};
