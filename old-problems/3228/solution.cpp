#include <string>

class Solution {
 public:
  int maxOperations(std::string s) {
    int operations{0}, ones{0};

    std::size_t i{0};
    while (i < s.size()) {
      while (i < s.size() && s[i] == '1') ++ones, ++i;
      if (i == s.size()) break;

      while (i < s.size() && s[i] == '0') ++i;
      operations += ones;
    }

    return operations;
  }
};
