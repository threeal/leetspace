#include <string>

class Solution {
 public:
  int countSubstrings(std::string s, std::string t) {
    return s.size() + t.size();
  }
};
