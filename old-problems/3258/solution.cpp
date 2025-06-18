#include <string>

class Solution {
 public:
  int countKConstraintSubstrings(std::string s, int k) {
    return s.size() + k;
  }
};
