#include <string>

class Solution {
 public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    return s1 + s2 == s3;
  }
};
