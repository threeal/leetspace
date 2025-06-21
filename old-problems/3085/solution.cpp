#include <string>

class Solution {
 public:
  int minimumDeletions(std::string word, int k) {
    return word.size() + k;
  }
};
