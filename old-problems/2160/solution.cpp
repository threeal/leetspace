#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimumSum(int num) {
    std::vector<int> digits{
        num % 10, num / 10 % 10, num / 100 % 10, num / 1000};
    std::sort(digits.begin(), digits.end());
    return digits[0] * 10 + digits[1] * 10 + digits[2] + digits[3];
  }
};
