#include <string>
#include <vector>

class Solution {
 public:
  int vowelStrings(std::vector<std::string>& words, int left, int right) {
    return words.size() + left + right;
  }
};
