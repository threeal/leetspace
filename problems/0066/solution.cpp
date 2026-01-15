#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    std::size_t i{digits.size() - 1};
    ++digits[i];

    while (i > 0 && digits[i] >= 10) {
      ++digits[i - 1];
      digits[i] %= 10;
      --i;
    }

    if (digits[i] >= 10) {
      digits.resize(digits.size() + 1);
      for (std::size_t j{digits.size() - 1}; j > 0; --j) {
        digits[j] = digits[j - 1];
      }
      digits[0] = 1;
      digits[1] %= 10;
    }

    return digits;
  }
};
