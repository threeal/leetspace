#include <string>

class Solution {
 public:
  int reverseDegree(std::string s) {
    int degree{0}, pos{0};
    for (const char c : s) {
      degree += (123 - c) * (++pos);
    }
    return degree;
  }
};
