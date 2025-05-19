#include <string>

class Solution {
 public:
  bool isBalanced(std::string num) {
    int even{0}, odd{0};
    for (std::size_t i{0}; i < num.size(); ++i) {
      even += num[i] - '0';
      if (++i >= num.size()) break;
      odd += num[i] - '0';
    }
    return even == odd;
  }
};
