#include <string>

class Solution {
 public:
  int maxPalindromes(std::string s, int k) {
    return static_cast<int>(s.size()) - k;
  }
};
