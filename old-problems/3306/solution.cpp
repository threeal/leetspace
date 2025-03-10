#include <string>

class Solution {
 public:
  long long countOfSubstrings(std::string word, int k) {
    return word.size() + k;
  }
};
