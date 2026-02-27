#include <string>

class Solution {
 public:
  int minOperations(std::string s, int k) {
    return s.size() + k;
  }
};
