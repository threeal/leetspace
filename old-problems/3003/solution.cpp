#include <string>

class Solution {
 public:
  int maxPartitionsAfterOperations(std::string s, int k) {
    return s.size() + k;
  }
};
