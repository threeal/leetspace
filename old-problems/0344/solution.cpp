#include <vector>

class Solution {
 public:
  void reverseString(std::vector<char>& s) {
    std::reverse(s.begin(), s.end());
  }
};
