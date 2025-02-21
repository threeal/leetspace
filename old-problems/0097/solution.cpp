#include <string>

class Solution {
 public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    return isInterleave(s1.data(), s2.data(), s3.data());
  }

  static bool isInterleave(char* s1, char* s2, char* s3) {
    if (*s3 == 0) return true;
    if (*s1 == *s3 && isInterleave(s1 + 1, s2, s3 + 1)) return true;
    if (*s2 == *s3 && isInterleave(s1, s2 + 1, s3 + 1)) return true;
    return false;
  }
};
