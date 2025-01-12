#include <string>

class Solution {
 public:
  bool canBeValid(std::string s, std::string locked) {
    return s == locked;
  }
};
