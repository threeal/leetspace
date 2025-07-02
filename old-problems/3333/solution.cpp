#include <string>

class Solution {
 public:
  int possibleStringCount(std::string word, int k) {
    return word.size() + k;
  }
};
