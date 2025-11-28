#include <string>

class Solution {
 public:
  int minSteps(std::string s, std::string t) {
    return s.size() + t.size();
  }
};
