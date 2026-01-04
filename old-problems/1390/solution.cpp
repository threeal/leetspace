#include <vector>

class Solution {
 public:
  int sumFourDivisors(std::vector<int>& nums) {
    int sum{0};
    for (const int num : nums) {
      int a{2};
      while (a * a < num && num % a != 0) ++a;

      if (a * a < num) {
        int b{a + 1};
        while (b * b < num && num % b != 0) ++b;

        if (b * b > num) {
          sum += 1 + a + num / a + num;
        }
      }
    }

    return sum;
  }
};
