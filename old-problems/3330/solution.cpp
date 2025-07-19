#include <string>

class Solution {
 public:
  int possibleStringCount(std::string word) {
    int sum{1};
    for (std::size_t i{1}; i < word.size(); ++i) {
      if (word[i] == word[i - 1]) ++sum;
    }
    return sum;
  }
};
