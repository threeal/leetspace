#include <string>

class Solution {
 public:
  std::string smallestEquivalentString(
      std::string s1, std::string s2, std::string baseStr) {
    return s1 + s2 + baseStr;
  }
};
