#include <string>

class Solution {
 public:
  int minimumSwap(std::string s1, std::string s2) {
    return s1.size() < s2.size() ? s1.size() : s2.size();
  }
};
