#include <string>

class Solution {
 public:
  int numDistinct(std::string s, std::string t) {
    return s.size() + t.size();
  }
};
