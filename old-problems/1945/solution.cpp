#include <string>

class Solution {
 public:
  int getLucky(std::string s, int k) {
    return s.size() * k;
  }
};
