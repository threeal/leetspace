#include <string>

class Solution {
 public:
  int getLengthOfOptimalCompression(std::string s, int k) {
    return s.size() - k;
  }
};
