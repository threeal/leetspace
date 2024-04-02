#include <string>

class Solution {
 public:
  std::string largestGoodInteger(std::string num) {
    char largestCh = 0;
    for (std::size_t i = 2; i < num.size(); ++i) {
      if (num[i] <= largestCh) continue;
      if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
        largestCh = num[i];
      }
    }

    return largestCh > 0 ? std::string(3, largestCh) : "";
  }
};
