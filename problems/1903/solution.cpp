// A number is odd if the last digit is odd, that is why we iterate
// from the last element to find the first occurrence of an odd digit.

#include <string>

class Solution {
 public:
  std::string largestOddNumber(std::string num) {
    // Iterating from the last element to find an odd digit.
    for (std::size_t i = num.size(); i > 0; --i) {
      if ((num[i - 1] - '0') % 2 != 1) continue;
      return num.substr(0, i);
    }

    // No odd digit found.
    return "";
  }
};
