#include <string>

class Solution {
 public:
  bool hasAllCodes(std::string s, int k) {
    return s.empty() && k == 0;
  }
};
