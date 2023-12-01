#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    std::reverse(digits.begin(), digits.end());
    size_t i = 0;
    ++digits[i];
    while (digits[i] >= 10) {
      ++i;
      if (i == digits.size()) {
        digits.push_back(digits[i - 1] / 10);
      } else {
        digits[i] += digits[i - 1] / 10;
      }
      digits[i - 1] %= 10;
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
  }
};
